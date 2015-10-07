#include "rpi.h"

/*
	RPI - Service Core
*/

//...Variables
char CZCore::prefix[BUFF_SIZE_L];
int CZCore::serverFileHandle = 0;
int CZCore::proccessMode = 0;

//...Functions
CZCore::CZCore(){
	strcpy ( prefix ,  "[CORE]: " );

}

int CZCore::initCore(){
    //...First Obtain server proccess file lock
    if (serverProcessCheck( ) > 0 ){
        //...TRUE : SERVER EXISTS
        proccessMode = AM_CLIENT;
    }else{
        //...NO SERVER
        proccessMode = AM_SERVER;
        if (CZCore::serverProcessLock ( ) < 0 ) {
            //...Couldn't file lock
            printf ( "%s Server Lock Proccess failed! \n" , prefix);
            perror("[ERROR]: ");
            return -1;
        }
    }

    //...What is the hardware infomation : CPU, RAM, IP
    printf("%s System infomation :\n\t# CPU's: %i\n\t# RAM: %i\n\t# IP: %s\n\t# Project Serial: %i\n\t# Pi Serial: %i\n",    
            prefix , getCPUCount() ,  getRAMCount() , gPi.getIpAddress() , PROJECT_SERIAL , gPi.getSerial() );


    //...Return proccess mode
    return proccessMode;
}

int CZCore::getServiceMode(){
    return proccessMode;
}

int CZCore::serverProcessCheck ( ){ //...Check for server file
	//...Checking for Server lock file
	printf ( "%s Checking Server lock file\n", prefix );
 	serverFileHandle = open(FILE_SERVER_PID, O_RDWR, 0666);
    if ( serverFileHandle < 0 && errno == ENOENT ) { 
        printf("%s No server file found\n", prefix );
        return -1;
    }else if (serverFileHandle < 0) {
        //...Error with file
        perror ( "[ERROR] Server file 'open' : ");
        return 0;
    }    

    //...Try and lock the fiel
    int rt = flock(serverFileHandle, LOCK_EX|LOCK_NB);
	if (rt < 0 && errno==EEXIST ) {
    	//...Find server PID and PORT
    	printf("%s Server File is locked\n" , prefix );
        serverFileHandle = 0;
    	return 1;
	} else if ( rt < 0 ){
        //..Unknown error
        perror ( "[ERROR] File lock failed because: ");
        printf("\n");
        return 1;
    } else {
	    flock(serverFileHandle, LOCK_UN);
	    printf("%s No server found\n", prefix);
         if ( unlink (FILE_SERVER_PID) < 0 ){
            //...Error
            printf("[Error] : File %s couldn't be removed \n", FILE_SERVER_PID );
        }
	    return -1;
	}
    return 0;
    
}

int CZCore::serverProcessLock ( ) {
	//...Lock server file
	printf("%sInital Server lock\n",prefix);
	printf("%sChecking for exisiting server lock \n",prefix);
	int serverPID =0, serverPort=0;
    char buf[BUFF_SIZE_S];

	//...Check
	if (serverProcessCheck() > 0 ) {
		printf ( "[Error]: Existing server exists PID: %i\n",serverPID,serverPort);
		return -1;
	}

	//...Lock the file
	serverFileHandle = open( FILE_SERVER_PID , O_CREAT | O_RDWR, 0666);
	if (flock( serverFileHandle , LOCK_EX|LOCK_NB) == -1) {
		//...Find server PID and PORT
    	printf("%sServer File is locked\n" ,prefix);
    	return -1;
		
	} else {
	    //flock(fileno(lockFile), LOCK_UN);
        snprintf(buf, BUFF_SIZE_S , "%ld\n", (long) getpid());
        if (write(serverFileHandle, buf, strlen(buf)) != strlen(buf))
            printf("[FATAL] Writing to PID file\n");
 
	    printf("%s %ld Proccess File Lock \n" , prefix , (long) getpid() );
	    return 1;
	}
}

int CZCore::serverProcessRelease ( ) {
    //....Release
    if ( serverFileHandle <= 0 ) {
        printf ( "%sNo file handle to unlock \n" , prefix );
    }else{
        flock(serverFileHandle, LOCK_UN);
        printf ( "%sServer File Lock Released\n" , prefix );
        //...Remove the file
        if ( unlink (FILE_SERVER_PID) < 0 ){
            //...Error
            printf("[Error] : File %s couldn't be removed \n", FILE_SERVER_PID );
        }
    }
}

/*
	#define RPI_SERIAL 0xFAB4C8A0 //...Unique serial for the PI
	#define RPI_CandC 0x15550BD3 //...RPi Seerial for C&C

	Becuase the RPI Project had multiple componets, it is important to use the correct serial for each:
	Q: WHy?
	A: Each project unique serial will handle same reponses differenty
		Example: 
			RPi-Service : Runs the core of the applications ( Run : CORE 1 )
			RPi-Find	: Find the Raspberry pies
			RPi-Canlogger: Can packet logger system ( Run : CORE 3 )
			RPi-Updater : Updating Service for the RPi service 
*/
int CZCore::RPiAuthenticate ( int serial ) {
    switch ( serial ){
        //...RPI SERIAL
        case PROJECT_SERIAL:
            return SERIAL_ID_RPI;
            break;

        //...C&C SERIAL
        case RPI_SERIAL:
            return SERIAL_ID_RPI;
            break;

        //...UNKNOWN
        default:
            return SERIAL_ID_UNKNOW;
            break;
    }
    return SERIAL_ID_UNKNOW;
}

int CZCore::getCPUCount (    ){
    //...get cpu count;
    return (int)sysconf (_SC_NPROCESSORS_ONLN);
}

int CZCore::getRAMCount(    ){
    return (int)sysconf ( _SC_PHYS_PAGES );
}

void CZCore::displayThreadInfo ( char * prefix ){
    //...Entry
    pthread_t _thread = pthread_self();
    cpu_set_t cpuset;

    //...Set the affiniaty
    CPU_ZERO(&cpuset);
    if ( pthread_getaffinity_np( _thread , sizeof(cpu_set_t), &cpuset) != 0 ) {
        //...Display error
        perror ( "[ERROR] 'pthread_setaffinity_np' : ");
        //# WE can still run, Just means multi-threading wont work
    }else{
        for (int j = 0; j < CPU_SETSIZE; j++)
               if (CPU_ISSET(j, &cpuset))
                printf("%s Proccess ID: %i CPU Worker: %i\n", prefix ,  getpid() , j );
    }
}