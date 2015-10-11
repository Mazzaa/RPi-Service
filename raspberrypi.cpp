#include "rpi.h"

char CRaspberryPi::prefix[BUFF_SIZE_M] = {"[Pi]:"};
int CRaspberryPi::instanceId = 0;

CRaspberryPi::CRaspberryPi()
{
	piPort = SERVER_PORT;
	strcpy (piIpAddress 	, CSocket::GetMultiIp ( CSocket::myhost() , 1) );
	strcpy (piMacAddress 	, CTools::getmacaddress()  );
	strcpy (piName 			, CSocket::myhost() );
	uniqueSerial = generateSerial();
}
CRaspberryPi::CRaspberryPi ( char*ip , unsigned short port , int piserial , char* name )
{
	piPort = port;
	strcpy (piIpAddress , ip );
	strcpy (piMacAddress , "AA:BB:CC:DD:EE:FF" );
	strcpy (piName ,  name );
	uniqueSerial = piserial;
}
CRaspberryPi::~CRaspberryPi()
{

}
void CRaspberryPi::resetPi (){
	piPort = SERVER_PORT;
	strcpy (piIpAddress 	, CSocket::GetIp ( CSocket::myhost() ) );
	strcpy (piMacAddress 	, CTools::getmacaddress()  );
	strcpy (piName 			, CSocket::myhost() );
	uniqueSerial = generateSerial();
}

//...Tools
bool CRaspberryPi::alive( )	//...is the pi live
{
	return ping() < NET_TTL;
}
unsigned short CRaspberryPi::ping( ) //...Returns the latency of the pi
{
	//...Process list
	int ping = 0,count=0;
	sPingHeartBeat* beat = NULL;

	for (std::vector<sPingHeartBeat *>::iterator it = heartBeats.begin() ; it != heartBeats.end(); ++it){
		beat = *it;
		if ( beat->done ){
			ping+= beat->ping;
			count++;
		}else{
			ping+= beat->timer.getElapsedTimeInMilliSec();
			count++;
		}
	}

	//...Check size
	while ( heartBeats.size() > 32 ){
		heartBeats.pop_back();
	}

   	//...Return ping by count of succesful pings average
	return static_cast<int>(ping / (count==0?1:count));
}

//...Gets
char * 	CRaspberryPi::getIpAddress ()
{ 
	return this->piIpAddress; 
}
unsigned short 	CRaspberryPi::getPort() 		
{ 
	return this->piPort; 
}
int CRaspberryPi::getSerial () 	
{ 
	return this->uniqueSerial;
}
char * CRaspberryPi::getMyName (){
	return this->piName;
}

int CRaspberryPi::generateSerial(){
	//...Generate 
	return randrange ( 22000 , 66000 );
}

/*
	struct sPingHeartBeat
	{
		int id;	 //...Unqiue id of the ping
		CTimer timer;
		int ping; // MS :
		bool done;
	};
*/

//...Ping Pi function
bool CRaspberryPi::pingPi ( CSocket * sock , CBuffer * buff ){
	//...Ping the pi
	if ( sock == NULL )return false;
	if ( buff == NULL )return false;

	printf("%s PI %i Sent HEART BEAT\n", prefix , uniqueSerial );

	//...Generate Heart beat packet
	sPingHeartBeat * beat = new sPingHeartBeat();
	beat->id = generateSerial();
	beat->timer.start();
	beat->done = false;
	beat->ping = 0;

	//...Check socket
	//buff->clear();	THIS CAUSES MEMORY ERRORS FROM THREADS : CAN'T ACCES THREAD STACK
    buff->writeint      ( PROJECT_SERIAL );
    buff->writebyte     ( RPI_NET_HEARTBEAT );	//...Heart beat is simple hello
    buff->writeint 	   	( uniqueSerial );		//...Serial Identifies the sender
    buff->writeint 	   	( beat->id );		//...Serial Identifies the sender

    //...Record Heart beat
    heartBeats.insert ( heartBeats.begin() , beat );

    return sock->sendmessage    ( piIpAddress , piPort , buff ) > 0;
}

/*
	struct sPingHeartBeat
	{
		int id;	 //...Unqiue id of the ping
		CTimer timer;
		int ping; // MS :
		bool done;
	};
*/

void CRaspberryPi::handlePing ( int heartBeatId ){
	//...Lookup ping : tick it off
	sPingHeartBeat * beat = NULL;
	for (std::vector<sPingHeartBeat *>::iterator it = heartBeats.begin() ; it != heartBeats.end(); ++it){
		beat = *it;
		//...Find id
		if ( beat->id == heartBeatId ){
			//...Fill out ping
			beat->timer.stop();
			beat->done = true;
			beat->ping = beat->timer.getElapsedTimeInMilliSec();
		}
	}
}