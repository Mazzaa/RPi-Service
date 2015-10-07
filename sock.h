#pragma once

#ifndef WIN_32
	typedef int SOCKET;
	typedef sockaddr_in SOCKADDR_IN;
	typedef sockaddr SOCKADDR, *LPSOCKADDR;
	typedef hostent HOSTENT, *LPHOSTENT;
	typedef in_addr IN_ADDR, *LPINADDR;
#endif

#define PROC_NULL		0x00
#define TCP_CONNECT 	0x01
#define TCP_LISTEN  	0x02
#define UDP_NORMAL  	0x03
#define UDP_MULTICAST 	0x04

class CSocket
{
	int proc;
	int format;
	char formatstr[30];
	static SOCKADDR_IN SenderAddr;
	SOCKADDR_IN udpAddr;
	struct ip_mreq mAddr;

	int receivetext(char*buf, int max);
public:

	SOCKET sockid;
	CSocket(SOCKET sock);
	CSocket();
	~CSocket();
	bool destroy();

	bool tcpconnect(char*address, int port, int mode);
	bool tcplisten(int port, int max, int mode);
	CSocket* tcpaccept(int mode);
	char* tcpip();
	void setnagle(bool enabled);
	bool tcpconnected();
	int setsync(int mode);

	bool udpconnect(int port, int mode);
	bool udpconnectmcast( char* multicast , int port , int mode );

	int sendmessage(char*ip, int port, CBuffer* source);
	int receivemessage(int len, CBuffer*destination);
	int peekmessage(int size, CBuffer*destination);

	//...is connected
	bool udpMulicastConnected();

	//...Tools
	int lasterror();
	static char* GetIp(char*address);
	static char* GetMultiIp ( char* address , int index );
	static int SockExit(void);
	static int SockStart(void);
	static char* lastinIP(void);
	static unsigned short lastinPort(void);
	static char* myhost();
	int SetFormat(int mode, char* sep);
};
