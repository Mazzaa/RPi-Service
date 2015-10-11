#pragma once

struct sPingHeartBeat
{
	int id;	 //...Unqiue id of the ping
	CTimer timer;
	int ping; // MS :
	bool done;
};



class CRaspberryPi {
	//...Private info
	unsigned short piPort;
	char piIpAddress[BUFF_SIZE_S];
	char piMacAddress[BUFF_SIZE_M];
	char piName[BUFF_SIZE_M];
	int uniqueSerial;

	//...List:
	/*
		Heart beats are used to measure pings on the rasperry pis
	*/
	std::vector<sPingHeartBeat *>	heartBeats; //...Queue FIFO C->B->A 

	//...Static prefix
	static char prefix[BUFF_SIZE_M];
	static int instanceId;

public:
	CRaspberryPi ( );
	CRaspberryPi ( char*ip , unsigned short port , int piserial , char* name );
	~CRaspberryPi();

	void resetPi ();

	//...Tools
	bool alive( );			//...is the pi live
	unsigned short ping( ); //...Returns the latency of the pi

	//...Gets
	char * 			getIpAddress ();
	unsigned short 	getPort();
	int 			getSerial ();
	char* 			getMyName();

	//...Static tools
	static int generateSerial(); //...generate unique serial	

	//...Ping Pi function
	bool pingPi ( CSocket * sock , CBuffer * buff );

	//...Hear beat handle : 
	void handlePing ( int heartBeatId );

};
