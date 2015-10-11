#pragma once

struct _tThreadArgs{
	int opsPort;
};

class CRPiService {

	//....Service thread
	static void *_ServiceThread( void * ptr ); //...Service thread

	static char prefix[BUFF_SIZE_L];
	pthread_t _pServiceThread;
	static _tThreadArgs threadData;
	
public:
	CRPiService();
	~CRPiService();

	//...Service init/destory
	bool initService ();
	bool stopService ();

	//...Check functions
	bool  isRunning();

	//...Passing data to the thread

	//...Set functions
	void setServicePorts ( int port );

protected:
		static volatile bool threadKill;
};