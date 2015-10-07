#include "rpi.h"

/*
	static void *_CanLoggerThread( void * ptr ); //...Service thread :
	static void *_CanProcessorThread ( void * ptr ); //...Data processor : 

	static char prefix[BUFF_SIZE_L];
	pthread_t _pCanLoggerThread;
	pthread_t _pCanProcessorThread;
*/

CCanLogger::CCanLogger(){
	
}
CCanLogger::~CCanLogger(){
	
}

bool CCanLogger::_runProcessThread ( ){
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
}

bool CCanLogger::_runProcessThread ( ){
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
}

//....Functions
bool CCanLogger::initCanLogger ( char * mcastIp ,  unsigned short port ){
	
}
bool CCanLogger::stopCanLogger (){
	
}

//...Check functions
bool  CCanLogger::isLoggerRunning(){
	
}
bool  CCanLogger::isProcessorRunning(){
	
} 

//...Functions
int CCanLogger::sendCanPacket ( CanPacket* packet ){

}
int CCanLogger::recvCanPacket ( CanPacket* packet ){

}

static bool threadKill;