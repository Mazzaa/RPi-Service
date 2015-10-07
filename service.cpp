#include "rpi.h"

bool CRPiService::threadKill = false;
char CRPiService::prefix[BUFF_SIZE_L];
_tThreadArgs CRPiService::threadData;

CRPiService::CRPiService(){
	strcpy ( prefix , "[RPI-THREAD]");
	threadData.opsPort = SERVER_PORT;
}

CRPiService::~CRPiService(){
	//...Check service
	if ( isRunning() ){
		stopService();
	}
}

void CRPiService::setServicePorts ( int port ){
	threadData.opsPort = SERVER_PORT;
}

//...Service init/destory
bool CRPiService::initService (){
	//...Start the service
	int cpuID = CPU_ID_SERVICE;
	cpu_set_t cpuset;

	// pthread_create (thread, attr, start_routine, arg) '
	_tThreadArgs * arg = new _tThreadArgs();
	arg->opsPort = threadData.opsPort;
	int rc = pthread_create(
							&_pServiceThread,
							NULL,
							&CRPiService::_ServiceThread,
							(void*)arg);
	//...Set the affiniaty
	CPU_ZERO(&cpuset);
    CPU_SET( cpuID , &cpuset);
	if ( pthread_setaffinity_np(_pServiceThread, sizeof(cpu_set_t), &cpuset) != 0 ) {
		//...Display error
		perror ( "[ERROR] 'pthread_setaffinity_np' : ");
		//# WE can still run, Just means multi-threading wont work
	}

	return isRunning();

}
bool CRPiService::stopService (){
	//..Stop the sarvice
	// pthread_exit (status) 
	threadKill = true;
	return pthread_cancel(NULL) == 0;
}

//...Check functions
bool  CRPiService::isRunning(){
	//...Check if running
	return !threadKill;
}

void *CRPiService::_ServiceThread( void * ptr ) //...Service thread
{
	_tThreadArgs * _tdata = (_tThreadArgs*)ptr;
	pthread_t _thread =  pthread_self();
	int opsPort = _tdata->opsPort;

	//...Due to MYSQL : Create a local Pi Handler
	CPiSQLHandler * qPiHandler = new CPiSQLHandler();
	qPiHandler->initConnector();
	qPiHandler->initHandler();

	//..Setup
    printf ("%s RPI UDP Discovery\n", prefix );
    CZCore::displayThreadInfo ( prefix );
	int recv_len = 0;

    //...Toolkit
    CBuffer rBuff;
    CBuffer sBuff;
    CSocket sock;
    CRaspberryPi * raspPi = NULL;

    char ip[16]; strcpy ( ip , "127.0.0.1" );

    char afix[BUFF_SIZE_M];
    strcpy ( afix , "[Discovery]: ");

    //...Check we can open udp sockets
    if (sock.udpconnectmcast ( SERVER_MULTCAST_ADDR , opsPort , 1 )<0){
        printf ( "[ERROR] : CSocket::udpconnect Failed" );
    }

    //...Send a broadcast
    sBuff.clear();
    //# HEADER
    sBuff.writeint  ( PROJECT_SERIAL );
    sBuff.writebyte ( RPI_NET_PING );

    //# DATA
    sBuff.writeint  ( gPi.getSerial() );

    if ( !sock.sendmessage ( "127.0.0.1" , SERVER_PORT , &sBuff ) ){
        printf("[ERROR]: SEND Discovery FAILED\n");
    }
    
    //...Reading
    char code = 0,errorOut = 0, ip_in[BUFF_SIZE_L] , spareBuff[BUFF_SIZE_X];
    unsigned short port_in = 0;
    int serial = 0,heartBeat = 0 , piSerial = 0;

    //keep listening for data
    while(1 && (threadKill==0))
    {

        fflush(stdout);
        rBuff.clear();
        sBuff.clear();

        //try to receive some data, this is a blocking call         
        do {
            recv_len = sock.receivemessage ( BUFF_SIZE_L , &rBuff );
        }while ( recv_len <= 0 );

        //...Retrieve last infomation
        strcpy ( ip_in ,    CSocket::lastinIP() );
        port_in         =   CSocket::lastinPort();

        //...Read : Header
        serial = rBuff.readint();
        code = rBuff.readbyte ();

        if ( CZCore::RPiAuthenticate(serial) > 0 ) {
            printf ( "%s Authentic: %i Code: %i | Bytes rec: %i \n" , afix , serial , code , recv_len );         
            
            // : Data 
            switch ( code ) {

                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //...We got a ping from a pi : Serial check
                /*
                    PACKET : NETWORK PING 
                        Structure :
                            - PI UNIQUE SERIAL ( INT 4 BYTES )
                */
                case RPI_NET_PING:
                {
                    piSerial = rBuff.readint ( );
                    printf ( "%s RPi NETWORK PING RECV : ID (%i)\n" , afix , piSerial );                   
                    
                    //...Write message 
                    sBuff.clear();

                    //...Header
                    sBuff.writeint      ( PROJECT_SERIAL );
                    sBuff.writebyte     ( RPI_NET_PONG );

                    //...Data packet
                    sBuff.writeint      ( gPi.getSerial() );
                    sBuff.writestring   ( gPi.getMyName() );

                    recv_len = sock.sendmessage    ( ip_in , port_in , &sBuff );

                    printf ( "%s Reply sent %i bytes to %s:%i \n" , afix ,recv_len, ip_in , port_in );         
                    break;        
                }

                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //...A Reply PONG to our PING
                /*
                    PACKET : NETWORK PONG ( PING -> PONG (Invokes) ) 
                        Structure :
                            - PI UNIQUE SERIAL ( INT 4 BYTES )
                            - NAME (STRING - MAX 255 )( PI PING Hostname )
                    Information:
                        PONG and PING are used for network discovery of the RPI network 
                */
                case RPI_NET_PONG:
                {
                    //...Pong reply :
                    piSerial = rBuff.readint ( );
                    char * t = rBuff.readstring();
                    strcpy ( spareBuff , t );

                    printf ( "%s RPi NETWORK PONG RECV : ID (%i)\n" , afix , piSerial ); 

                    //...Check : NON EXIST
                    if ( !qPiHandler->checkPi ( ip_in , port_in , piSerial ) ){
                        //...Exists
                        raspPi = new CRaspberryPi ( ip_in , port_in , piSerial , spareBuff );
                        if ( !qPiHandler->registerPi ( raspPi ) ){
                            printf("%s Failed to register PI : See MYSQL Error\n", prefix );
                        }
                    }
                    delete raspPi;

                    break;
                } 

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //...Keep alive : Keep connection alive
                /*
                    PACKET : HEART BEAT ( HALF BEAT - Draw breath ) 
                        Structure :
                            - PI UNIQUE SERIAL ( INT 4 BYTES )
                            - Heart Beat id ( INT 4 Bytes )
                    Information:
                        Heart beat is used to check that pi's are alive and beating
                */
                case RPI_NET_HEARTBEAT:
                {
                    printf("%s WE ARE BEATING\n", "[HEART-BEAT]: " );
                    //...Heart beat : We are to respond
                    serial = rBuff.readint ( );
                    heartBeat = rBuff.readint(); //..Unique heart beat id:
                    sBuff.clear();

                    //...Heart beat : Ping
                    int ret = qPiHandler->checkPi ( ip_in , port_in , serial ); //...LOOK UP IF EXISTING ( IP : PORT : SERIAL );
                    if ( qPiHandler->checkPi ( ip_in , port_in , serial ) ){
                        //...Header
                        /*sBuff.writeint ( PROJECT_SERIAL );      //...Application version/identification
                        sBuff.writebyte( RPI_NET_HEAREDBEAT );  //...NETWORK PROTOCAL

                        //...Write data packer for heart beated
                        sBuff.writeint ( gPi.getSerial() );     //...Write our serial
                        sBuff.writeint ( heartBeat );           //...Heart beat reply

                        if (sock.sendmessage    ( ip_in , port_in , &sBuff )<0){
                            printf ( "[ERROR] SOCKET SEND FAILED\n");
                        }*/
                    }
                    break;
                }

                /////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //...Keep alive : Keep connection alive
                /*
                    PACKET : HEART BEATED ( FULL BEAT - Exhale breath ) 
                        Structure :
                            - PI UNIQUE SERIAL ( INT 4 BYTES )
                            - Heart Beat id ( INT 4 Bytes )
                    Information:
                        Heart beat registered. The other pi responded
                */
                case RPI_NET_HEAREDBEAT:
                {
                    printf("%s HEART BREAT ALIVE\n", "[HEART-BEAT]: " );
                    //...Heart beat responsed
                    piSerial = rBuff.readint ( ); //...Who's it from
                    heartBeat =  rBuff.readint(); //...Read the heart beat

                    bool ret = qPiHandler->checkPi ( ip_in , port_in , serial ); //...LOOK UP IF EXISTING ( IP : PORT : SERIAL );
                   
                    sBuff.clear();

                    //....What did the check say?
                    if ( ret ) {
                        
                        //...Look up pi :
                        CRaspberryPi * pi = NULL;
                        pi = qPiHandler->getPi( serial );

                        if ( pi != NULL ){
                            //...Tick off heart beat
                            pi->handlePing ( heartBeat );

                        }else{
                            printf("[FATAL] UNREACHABLE CODE!!! : RPI_NET_HEAREDBEAT : Pi Check TRUE : getPi : FALSE \n");
                        }

                    }else{

                        //# PI : YOU CANT HEART BEAT ME IF YOU DONT EXIST
                        sBuff.writeint ( PROJECT_SERIAL );      //...Application version/identification
                        sBuff.writebyte( RPI_NET_PING );        //...NETWORK PROTOCAL
                        sBuff.writeint ( gPi.getSerial() );     //...Write our serial

                        if (sock.sendmessage    ( ip_in , port_in , &sBuff )<0){
                            printf ( "[ERROR] SOCKET SEND FAILED\n");
                        }
                    }

                    break;
                }
                default:
                {
                        printf ( "%s Uknown code: %c \n" , prefix , code );
                        rBuff.clear();
                        break;
                }
            }

            //...Clean the buffer
            rBuff.clear();
        }else{
            printf ( "[NOTICE] Bad serial: %s:%i \n" , ip_in , port_in );
        }
    }

    //..Setup
    printf ("%s RPI UDP Discovery Finnished \n", prefix );
    sock.destroy();
    qPiHandler->resetPiTable();
    pthread_exit(NULL);
}