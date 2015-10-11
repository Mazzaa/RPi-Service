#include "rpi.h"

/*
	static void *_CanLoggerThread( void * ptr ); //...Service thread :
	static void *_CanProcessorThread ( void * ptr ); //...Data processor : 

	static char prefix[BUFF_SIZE_L];
	pthread_t _pCanLoggerThread;
	pthread_t _pCanProcessorThread;
*/
char CCanLogger::prefix[BUFF_SIZE_L];

CCanLogger::CCanLogger(){
	strcpy ( prefix , "[CAN-LOG]: ");
}
CCanLogger::~CCanLogger(){
	
}
/*
#define CPU_ID_CAN_LOGGER 2
#define CPU_ID_DATA_PROCCESSOR 1
*/

//pthread_t CCanLogger::_pCanLoggerThread;
//pthread_t CCanLogger::_pCanProcessorThread;

bool CCanLogger::_runLoggerThread ( )
{
	char prefix[BUFF_SIZE_L]; strcpy ( prefix , "[LOG-THREAD]: " );
	int cpuID = CPU_ID_CAN_LOGGER;
	cpu_set_t cpuset;
	// pthread_create (thread, attr, start_routine, arg) '
	int rc = pthread_create(
							&_pCanLoggerThread,
							NULL,
							&CCanLogger::_CanLoggerThread,
							(void*)NULL);
	//...Set the affiniaty
	CPU_ZERO(&cpuset);
    CPU_SET( cpuID , &cpuset);
	if ( pthread_setaffinity_np(_pCanLoggerThread, sizeof(cpu_set_t), &cpuset) != 0 ) {
		//...Display error
		perror ( "[ERROR] 'pthread_setaffinity_np' : ");
		//# WE can still run, Just means multi-threading wont work
	}

	
	return rc == 0;
}

bool CCanLogger::_runProccessThread ( ){
	//...Start the service
	char prefix[BUFF_SIZE_L]; strcpy ( prefix , "[DATA-THREAD]: " );
	int cpuID = CPU_ID_DATA_PROCCESSOR;
	cpu_set_t cpuset;

	// pthread_create (thread, attr, start_routine, arg) 
	int rc = pthread_create(
							&_pCanProcessorThread,
							NULL,
							&CCanLogger::_CanProcessorThread,
							(void*)NULL);
	//...Set the affiniaty
	CPU_ZERO(&cpuset);
    CPU_SET( cpuID , &cpuset);
	if ( pthread_setaffinity_np(_pCanProcessorThread, sizeof(cpu_set_t), &cpuset) != 0 ) {
		//...Display error
		perror ( "[ERROR] 'pthread_setaffinity_np' : ");
		//# WE can still run, Just means multi-threading wont work
	}

	return rc == 0;
}

//....Functions
bool CCanLogger::initCanLogger ( char * mcastIp ,  unsigned short port ){
	return _runLoggerThread() && _runProccessThread();
}
bool CCanLogger::stopCanLogger (){
	return true;	
}

//...Check functions
bool  CCanLogger::isLoggerRunning(){
	return threadKillLogger;
}
bool  CCanLogger::isProcessorRunning(){
	return threadKillProcessor;
} 

bool CCanLogger::threadKillLogger = false;
bool CCanLogger::threadKillProcessor = false;

void * CCanLogger::_CanLoggerThread( void * ptr ) //...Service thread :
{
	//...Grab entry data
	char prefix[BUFF_SIZE_L]; strcpy ( prefix , "[LOGGER-THREAD]: " );
	printf("%s ENTRY POINT \n", prefix );
	CZCore::displayThreadInfo( prefix );

	//...Begin logging
	//...Statistics
	unsigned int 	packet_count,			//...Number of packets counted
					packet_rate,			//...Rate of packets / 1
					packet_count_lastindex; //...Packet index last

	unsigned int 	data_total_bytes,		//...Counting the bytes
					data_rate_bytes,		//...Byte rates
					data_bytes_last;		//...Last index of bytes


	//...Network
	CSocket * sock = new CSocket();
	CBuffer buff;
	CTimer  timer;
	int recv_len;
	CanPacket * packet;
	CCanLoggerDictonary _lhex_id_data;

	//...Create dictonary
	if ( _lhex_id_data.initDictonary() ){
		//...Display dictonary source
		
	}
	//...Import hard coded dictonary
    _lhex_id_data.initImportHardCoded();
    printf("%s Dictonary imported : %i records sucessfully\n", prefix , _lhex_id_data.getRecordCount() );

	//...Connect to can network
	if ( !sock->udpconnectmcast ( SERVER_MULTCAST_ADDR , SERVER_CANBUS_PORT , 1 ) ) {
		printf("[ERROR] THREAD LOGGER UDP MULT-CAST CONNECT FAIL!\n");
		pthread_exit ( NULL );
	}else{
		printf("%s CAN-LOGGER LISTENING ON: %s:%i\n", prefix , SERVER_MULTCAST_ADDR , SERVER_CANBUS_PORT  );
	}

	//...Wait for can packets
	while ( !CCanLogger::threadKillLogger ){
		//...Recive can-bus
		buff.clear();
		do {
			recv_len = sock->receivemessage ( BUFF_SIZE_M , &buff );
		}while ( recv_len);
		printf("TESTING\n");
		//...Record 
		packet = new CanPacket ( &buff );

		//...Check dictonary for existing id :
		if ( _lhex_id_data.checkExist ( packet->getID() ) )
		 {
			//...Proccess packet
			printf("%s Hex: %#03x : %s From network\n", prefix , packet->getID() , _lhex_id_data.getRecordName( packet->getID() )  );
			delete packet;
			packet = NULL;
		}else{
			printf("[WARNING] BAD PACKET\n");
			//...Drop packet
			delete packet;
			packet = NULL;
		}

	}

	sock->destroy();
	delete sock;

	//...Exit
	pthread_exit( NULL );
}
void * CCanLogger::_CanProcessorThread ( void * ptr ) //...Data processor : 
{
	//...Grab entry data
	char prefix[BUFF_SIZE_L]; strcpy ( prefix , "[DATA-THREAD]: " );
	printf("%s ENTRY POINT \n", prefix );
	CZCore::displayThreadInfo( prefix );

	char sqlInsert[BUFF_SIZE_Z]; //...SQL: Alllocate 2048 bytes : Really long SQL querys; Just in case
	CBuffer * canData;
	CanPacket * packet = NULL;
	int QueueProcess = 2; //...Proccess Q 2

	//...Import
	while ( !CCanLogger::threadKillProcessor){
		//...Check free queue for proccessing
		/*
			Because the program is multi-threaded ( Badly :S )
			we requre multiple streams for data to be stored in:
				In theory we would need 2 Queues for storing

				P1 ( Can logger );
				P2 ( Processor );

				Q1 ( Queue one )
				Q2 ( Queue two )

				Logic:
				P1:
					IF Q1 NOT LOCKED
						-> RECORD TO Q1 UNTIL SIZE > 64 packets
							AND Q2 is free
					IF Q1 AND Q2 NOT LOCKED 
						USE Q1
					IF Q1 LOCKED AND P2.Q2 IS PROCCESSING AND Q1 SIZE > 64 
						CONTINUE RECORD 
						WAIT Q1

					# P1 Will switch between Q1 AND Q2
				
				# P2 Must wait for the locks to be released on Q1|Q2 before locking.
				P2:
					IF Q1 NOT LOCKED AND Q2 IS LOCKED
						P1.LOCK Q1 THEN PROCESS
						WAIT FOR Q2 
		*/

		//...Proccess packets
		



	}


	//...Exit
	pthread_exit( NULL );
}