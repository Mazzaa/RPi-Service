#ifndef CORE_H
#define CORE_H

class CZCore {
	static char prefix[BUFF_SIZE_L];
	static int serverFileHandle;
	static int proccessMode; 	
	public:
		CZCore ();

		int initCore();

		int getServiceMode();

		//...Service Locks
		static int serverProcessCheck ( ); //...Check for server file
		static int serverProcessLock  ( );
		static int serverProcessRelease( );

		//...Authentication
		static int RPiAuthenticate ( int serial );

		static int getCPUCount (	);
		static int getRAMCount ( 	);

		static void displayThreadInfo ( char * prefix );
};

#endif 