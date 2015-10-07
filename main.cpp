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

CPiSQLHandler * qPiHandler;

int SigExit = 0;
char prefix[BUFF_SIZE_L];

//# PROTOTYPE 
void runRPi (); //...Run Discoverry
void die (const char* s );
void sigHandler (int sig);

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

    CZCore::displayThreadInfo ( prefix );

    //...Proccess
    while ( 1 &&  !SigExit){

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
