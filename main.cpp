/*
  	RPI Discovery Testing
*/
#include "rpi.h"

/*
    RPI Service : Used for the Solarcar project at 
        western sydney. 

    Thread
        CPU 0 : Main Service Thread ( Discovery | output etc )
        CPU 1 : CanLogger Service ( CAN-NETWORk -> QUEUE )
        CPU 2 : CanProccessor Service ( QUEUE -> MYSQL Network )
*/


int SigExit = 0;
char prefix[BUFF_SIZE_L];

//# PROTOTYPE 
void runRPi (); //...Run Discoverry
void die (const char* s );
void sigHandler (int sig);
void sigExceptionHandler ( int sig );

void setThreadCPU ();

//...Entry point
int main ( int agc , char * argv[] ) {
	//...Inital
	int mode = 0;
    strcpy ( prefix , "[RPI]: " );
    setThreadCPU();
    CZCore::displayThreadInfo ( prefix );

    // : ENTRY TO APPLICATIONS :
    signal(SIGINT, sigHandler );
    signal(SIGSEGV, sigExceptionHandler );

    //...ENABLE - THREAD MEMORY SHARE
    pthread_mutexattr_init(&gMemoryShare);

    //...Set shared data
    if ( pthread_mutexattr_setpshared(&gMemoryShare, PTHREAD_PROCESS_SHARED) != 0 ) {
        //...Display error
        perror ( "[ERROR] 'pthread_mutexattr_setpshared' : ");
        //# WE can still run, Just means multi-threading wont work
    }

    gPi.resetPi();

    //...Init services
    if ( gCore.initCore() < 0 ) {
        printf("%s CORE INIT FAILED! FORCED RE-START REQUIRED\n", prefix );
        return -1;
    }

    //...Begin service
    if ( !gService.initService() ) {
        printf ( "[ERROR] RPI Service Failed to start\n" );
        return -2;
    }

    //...Initalise dictonary
    if ( !ghex_id_data.initDictonary() ){
        printf ( "[ERROR] HEX ID dictonary init failed\n" );
        return -3;
    }
    
    //...Import hard coded dictonary
    ghex_id_data.initImportHardCoded();
    printf("%s Dictonary imported : %i records sucessfully\n", prefix , ghex_id_data.getRecordCount() );
    
    //...Initalise Can_logger
    if ( !gCanLogger.initCanLogger ( SERVER_MULTCAST_ADDR , SERVER_CANBUS_PORT )) {
        printf ( "[ERROR] Can Logger Init Service Failed\n" );
        return -4;
    }


    CZCore::displayThreadInfo ( prefix );

	int opsPort = randrange (22600 ,22700 );
	if ( gCore.getServiceMode() == AM_SERVER ) {
		opsPort = SERVER_PORT; //...If server assign
	}

	//...Run the system
    runRPi ();

    //...Clean up:
    CZCore::serverProcessRelease();
    //gPi.resetPi();
    if (!gService.stopService()){
        printf("[ERROR] SERVICE THREAD STOP ERROR \n");
    }

	//...Exit application
    printf ("%s SERVICE - EXIT\n",prefix);
    printf ("Goodbye! :)\n");
	return 0;
}



int sendmessage(char*ip, int port, CBuffer* source){
    return 0;
}

void die ( const char *s )
{
    perror(s);
    exit(1);
}

void  sigHandler (int sig)
{
    //...Exception caught
    printf ("\n");
    printf ( "Interrupt called : Code %i \n" ,  sig  );
    CZCore::serverProcessRelease ( );
    gService.stopService();
    gPi.resetPi();
    SigExit = 1;
    for ( int i=3;i>0;i--){
        printf("%s FORCED SHUTDOWN IN %i\n", prefix , i );
        sleep(1);
    }
    exit(1);
}

void runRPi (){
    //...Due to MYSQL : Create a local Pi Handler
    sleep(5);
    CZCore::displayThreadInfo ( prefix );
    CTimer mTimer;
    mTimer.start();
    CRaspberryPi * tPi;

    CSocket sock;
    CBuffer buff;

    if (sock.udpconnectmcast(SERVER_MULTCAST_ADDR_RPI , SERVER_PORT_OUT , 1 )<0){
        printf ( "[ERROR] : CSocket::udpconnectmcast Failed" );
    }
    else{
        printf("%s RPi-Service 'MAIN' LISTENING ON: %s:%i\n", prefix , SERVER_MULTCAST_ADDR_RPI , SERVER_PORT_OUT  );
    }


    //...Counter
    double pingTimeLast = mTimer.getElapsedTimeInMilliSec(),
            timeNow = mTimer.getElapsedTimeInMilliSec();

    for ( int i=0;i<3;i++)
        gPi.pingPi ( &sock , &buff );

    //...Proccess
    while ( 1 &&  !SigExit){
        //...Time now
        timeNow = mTimer.getElapsedTimeInMilliSec();

        //...Handle Pi's keep alive
        if ( pingTimeLast + NET_TTL < timeNow ){

            // Lock list first
            pthread_mutex_lock(&gPiListLock);

            //...Iterate the loop
            for (std::vector<CRaspberryPi * >::iterator it = gPiList.begin() ; it != gPiList.end(); ++it){
                tPi = *it;
                if (!tPi->pingPi ( &sock , &buff )){
                    printf("[WARNING] SEND HEART BEAT FAILED\n");
                }else{
                    printf("%s Hear-breat: %s:%i\n", prefix , tPi->getIpAddress() , tPi->getPort() );
                }
            }
            //...Release code
            pthread_mutex_unlock(&gPiListLock);
            pingTimeLast = timeNow;
            //printf("%s SENDING HEART BEAT\n", prefix );
        }


        sleep(1);   //...Reduces cpu time
    }
    //...Leave
}

void setThreadCPU(){
    pthread_t _thread = pthread_self();
    int cpuID = 0;
    cpu_set_t cpuset;

    //...Set the affiniaty
    CPU_ZERO(&cpuset);
    CPU_SET( cpuID , &cpuset);
    if ( pthread_setaffinity_np(_thread, sizeof(cpu_set_t), &cpuset) != 0 ) {
        //...Display error
        perror ( "[ERROR] 'pthread_setaffinity_np' : ");
        //# WE can still run, Just means multi-threading wont work
    }
}

void sigExceptionHandler ( int sig ){
    printf("--# Exception Raised #--\n\tTrace back: \n");
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}
