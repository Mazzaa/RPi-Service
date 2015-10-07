#pragma once

/*
	RPI Can logger Class

	Information:
		Tritium doesn't provide a Linux based OS port of the c++ class for interfacing with the can network.
		This means we need to write our own, Given what we know from creating 'killcar' ,  'buzzcar' functions previously written in C,
		we can determine how write a simple interface that can take can network packets and decode these into data to be ported into the
		MYSQL Database.

		For this to happen and work we need to break this down into three components
		- Dictonary ( The data structure used to decode the packets )
		- Network Logger ( Recvieve & Decode )
		- Proccessor ( Proccess the data, inserting into the MYSQL database )
			- Translator : Data will be basic structure used to indentify 'Feild name', 'datatype','bitsize'
				No we need to ensure same data format and improve efficeny


*/

class CCanLogger  {
	private:

		static void *_CanLoggerThread( void * ptr ); //...Service thread :
		static void *_CanProcessorThread ( void * ptr ); //...Data processor : 

		static char prefix[BUFF_SIZE_L];
		pthread_t _pCanLoggerThread;
		pthread_t _pCanProcessorThread;

		//...Dictonary
		bool _runLoggerThread ( );
		bool _runProccessThread ( );
	
	public:
		CCanLogger();
		~CCanLogger();

		//....Functions
		bool initCanLogger ( char * mcastIp ,  unsigned short port );
		bool stopCanLogger ();

		//...Check functions
		bool  isLoggerRunning();	// Logger process ( Net -> DATA )
		bool  isProcessorRunning(); // Processor ( Data -> MYSQL )

		//...Functions
		int sendCanPacket ( CanPacket* packet );
		int recvCanPacket ( CanPacket* packet );

	protected:
			static bool threadKill;


};