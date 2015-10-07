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
	return 0;
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

//...Ping Pi function
bool CRaspberryPi::pingPi ( CSocket * sock , CBuffer * buff ){
	//...Ping the pi
	if ( sock == NULL )return false;
	if ( buff == NULL )return false;
	int heartBeatId = generateSerial();

	printf("%s PI %i Sent HEART BEAT\n", prefix , uniqueSerial );

	//...Check socket
	buff->clear();
    buff->writeint      ( PROJECT_SERIAL );
    buff->writebyte     ( RPI_NET_HEARTBEAT );	//...Heart beat is simple hello
    buff->writeint 	   	( uniqueSerial );		//...Serial Identifies the sender
    buff->writeint 	   	( heartBeatId );		//...Serial Identifies the sender

    return sock->sendmessage    ( piIpAddress , piPort , buff );
}

void CRaspberryPi::handlePing ( int heartBeatId ){
	//...Lookup ping : tick it off

	/*
	SHeartBeat * n = heartBeatList.getHeartBeat ( heartBeatId );

	if ( n == NULL ){
		printf ( "%s Unknown heart beat %i\n");
	}else{
		//...Tick it off
		n.recieved();
	}
	*/
}