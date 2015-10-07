#include "rpi.h"

typedef sockaddr_in SOCKADDR_IN;

#define max(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; } )
#define min(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; } )

socklen_t SenderAddrSize = sizeof(SOCKADDR_IN);
SOCKADDR_IN CSocket::SenderAddr;

bool CSocket::tcpconnect(char *address, int port, int mode)
{
	SOCKADDR_IN addr;
	LPHOSTENT  hostEntry;
	if((sockid = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) == SOCKET_ERROR)
        return false;
	if((hostEntry = gethostbyname(address))==NULL)
	{
		close(sockid);
		return false;
	}
	
	//..Fill out addres
	addr.sin_family = AF_INET;
	// ... FIX THIS
	//addr.sin_addr = hostEntry->h_addr ; // struct in_addr   sin_addr;     // see struct in_addr, below GetIp
	bcopy((char *)hostEntry->h_addr,(char *)&addr.sin_addr.s_addr,hostEntry->h_length);
	addr.sin_port = htons((u_short)port);
	if(mode ==2)setsync(1);

	//...Connect socket
	int rc = connect(sockid, (struct sockaddr *)&addr, sizeof(addr));
	if(rc == SOCKET_ERROR)
	{
		if(errno == EWOULDBLOCK)
		{
			close(sockid);
			return false;
		}
	}
	if(mode ==1)setsync(1);
	proc = TCP_CONNECT;
	return true;
}

bool CSocket::tcplisten(int port, int max, int mode)
{
	if((sockid = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) return false;
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	if(mode)setsync(1);
	if(bind(sockid, (LPSOCKADDR)&addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		close(sockid);
		return false;
	}
	if(listen(sockid, max) == SOCKET_ERROR)
	{
		close(sockid);
		return false;
	}
	proc = TCP_LISTEN;
	return true;
}

CSocket::CSocket(SOCKET sock)
{
	sockid = sock;
	proc = PROC_NULL;
	format = 0;
	proc = TCP_CONNECT;
}
CSocket::CSocket()
{
	proc = PROC_NULL;
	format = 0;
}



CSocket::~CSocket()
{
	if(sockid<0)return;
	shutdown(sockid, 1);
	close(sockid);
}

bool CSocket::destroy() {
	if(sockid<0)return false;
	shutdown(sockid, 1);
	close(sockid);
	proc = PROC_NULL;
	return true;
}

CSocket* CSocket::tcpaccept(int mode)
{
	if(sockid<0)return NULL;
	SOCKET sock2;
	if((sock2 = accept(sockid, (SOCKADDR *)&SenderAddr, &SenderAddrSize)) != INVALID_SOCKET)
	{
		CSocket*sockit = new CSocket(sock2);
		if(mode >=1)sockit->setsync(1);
		return sockit;
	}
	return NULL;
}

char* CSocket::tcpip()
{
	if(sockid<0)return NULL;
	if(getpeername(sockid, (SOCKADDR *)&SenderAddr, &SenderAddrSize) == SOCKET_ERROR)return NULL;
	return inet_ntoa(SenderAddr.sin_addr);
}

void CSocket::setnagle(bool enabled)
{
	if(sockid<0)return;
	setsockopt(sockid, IPPROTO_TCP, TCP_NODELAY,(char*)&enabled, sizeof(bool));
}

bool CSocket::tcpconnected()
{
	if(sockid<0)return false;
	char b;
	if(recv(sockid, &b, 1, MSG_PEEK) == SOCKET_ERROR)
		if(errno == EWOULDBLOCK)return false;
	return true;
}

int CSocket::setsync(int mode)
{
	if(sockid < 0)return -1;
	u_long i = mode;
	return ioctl (sockid, FIONBIO , &i);
}

bool CSocket::udpconnect(int port, int mode)
{
	SOCKADDR_IN addr;
	if((sockid = socket(AF_INET, SOCK_DGRAM, 0)) == SOCKET_ERROR)
        return false;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	if(mode)setsync(1);
	if(bind(sockid,(SOCKADDR *)&addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		close(sockid);
		return false;
	}
	proc = UDP_NORMAL;
	return true;
}

bool CSocket::udpconnectmcast( char* multicast , int port , int mode ){
	//...Create socket
	if((sockid = socket(AF_INET, SOCK_DGRAM, 0)) == SOCKET_ERROR)
        return false;    
	
	u_int reuse = 1;
	if (setsockopt(sockid,SOL_SOCKET,SO_REUSEADDR, &reuse, sizeof(u_int) ) < 0) {
		return false;
	}

	/* set up destination address */
	memset(&udpAddr,0,sizeof(udpAddr));
	udpAddr.sin_family = AF_INET;
	udpAddr.sin_addr.s_addr = inet_addr ( multicast );
	udpAddr.sin_port = htons(port);
	if(mode)setsync(1);
	/* bind to receive address */
	if (bind(sockid,(struct sockaddr *) &udpAddr,sizeof(udpAddr)) < 0) {
		return false;
	}

	/* use setsockopt() to request that the kernel join a multicast group */
	mAddr.imr_multiaddr.s_addr=inet_addr ( multicast );
	mAddr.imr_interface.s_addr=htonl(INADDR_ANY);

	//...Join membership
	if (setsockopt(sockid,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mAddr,sizeof(mAddr)) < 0) {
		return false;
	}
	proc = UDP_MULTICAST;
	return true;
}

int CSocket::sendmessage(char *ip, int port, CBuffer *source)
{

	if(sockid<0)return -1;
	int size = 0;
	SOCKADDR_IN addr;
	if(proc == UDP_NORMAL )
	{
		size = min(source->count, 8195);
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
		size = sendto(sockid, source->data, size, 0, (SOCKADDR *)&addr, sizeof(SOCKADDR_IN));
	}
	else if ( proc == UDP_MULTICAST ) 
	{
		//...UDP MULTI-CAST RE-USES SAME ADDRESS
		size = min(source->count, 8195);
		size = sendto(sockid, source->data, size, 0, (SOCKADDR *)&udpAddr, sizeof(SOCKADDR_IN));
	}
	else
	{
		CBuffer sendbuff;
		sendbuff.clear();
		if(format == 0)
		{
			sendbuff.writeushort(source->count);
			sendbuff.addBuffer(source);
			size = send(sockid, sendbuff.data, sendbuff.count, 0);
		}else if(format == 1)
		{
			sendbuff.addBuffer(source);
			sendbuff.writechars(formatstr);
			size = send(sockid, sendbuff.data, sendbuff.count, 0);
		}else if(format == 2)
			size = send(sockid, source->data, source->count, 0);
	}
	if(size == EWOULDBLOCK)return -errno;
	return size;
}

int CSocket::receivetext(char*buf, int max)
{
	int len = (int)strlen(formatstr);
	//r == -1     /* or r < 0 */
	max = recv(sockid, buf, max, MSG_PEEK);            
	if(max < 0 && errno == EWOULDBLOCK)
	{
		int i, ii;
		for(i = 0; i < max; i ++)
		{
			for(ii = 0; ii < len; ii++)
				if(buf[i+ii] != formatstr[ii])
					break;
			if(ii == len)
				return recv(sockid, buf, i + len, 0);
		}
	}
	return -1;
}
int CSocket::receivemessage(int len, CBuffer*destination)
{
	if(sockid<0)return -1;
	int size = -1;
	char* buff = NULL;
	if(proc == UDP_NORMAL || proc == UDP_MULTICAST )
	{
		size = 8195;
		buff = new char[size];
		size = recvfrom(sockid, buff, size, 0, (SOCKADDR *)&SenderAddr, &SenderAddrSize);
	} 
	else
	{
		if(format == 0 && !len)
		{
			unsigned short length;
			if(recv(sockid, (char*)&length, 2, 0) == SOCKET_ERROR)return -1;
			buff = new char[length];
			size = recv(sockid, buff, length, 0);
		} else if(format == 1 && !len)
		{
			size = 65536;
			buff = new char[size];
			size = receivetext(buff, size);
		} else if(format == 2 || len > 0)
		{
			buff = new char[len];
			size = recv(sockid, buff, len, 0);
		}
	}
	if(size > 0)
	{
		destination->clear();
		destination->addBuffer(buff, size);
	}
	if(buff != NULL)delete buff;
	return size;
}

int CSocket::peekmessage(int size, CBuffer*destination)
{
	if(sockid<0)return -1;
	if(size == 0)size = 65536;
	char *buff = new char[size];
	size = recvfrom(sockid,						//...Socket discriptor ( SOCKET (int));
					 buff, 						//...Buffer to recv data
					 size, 						//...Size of data to recv
					 MSG_PEEK,					//...Peek message 
					 (sockaddr *)&SenderAddr,	
					 &SenderAddrSize);				
	/*
		sock.cpp:238:88: error: invalid conversion from ‘int*’ to ‘socklen_t* {aka unsigned int*}’ [-fpermissive]
  			size = recvfrom(sockid, buff, size, MSG_PEEK, (sockaddr *)&SenderAddr, &SenderAddrSize);
	*/
	//en = recvfrom(sockid, buff, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == -1)    
	if(size < 0)
	{
		delete buff;
		return -1;
	}
	destination->clear();
	destination->addBuffer(buff, size);
	delete buff;
	return size;
}

int CSocket::lasterror()
{
	return errno;
}

char* CSocket::GetIp(char*address)
{
	return GetMultiIp ( address , 0 );
}

char* CSocket::GetMultiIp ( char* address , int index ){
	struct addrinfo hints, *res, *p;
	int status,count=0;
	char ipstr[INET6_ADDRSTRLEN];

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
	hints.ai_socktype = SOCK_STREAM;

	if ((status = getaddrinfo(address, NULL, &hints, &res)) != 0) {
		fprintf(stderr, "[SOCK] getaddrinfo: %s\n", gai_strerror(status));
		return "";
	}
	for(p = res;p != NULL; p = p->ai_next) {
		void *addr;		
		count++;
		// get the pointer to the address itself,
		// different fields in IPv4 and IPv6:
		if (p->ai_family == AF_INET) { // IPv4
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);			
		} else { // IPv6
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);			
		}
		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);

		if ( index == count ){
			return ipstr;
		}
	}	
	return ipstr;
}

char* CSocket::lastinIP(void)
{
	return inet_ntoa(SenderAddr.sin_addr);
}

unsigned short CSocket::lastinPort(void)
{
	return ntohs(SenderAddr.sin_port);
}

int CSocket::SetFormat(int mode, char* sep)
{
	int previous = format;
	format = mode;
	if(mode == 1 && strlen(sep)>0)
		strcpy(formatstr, sep);
	return previous;
}

int CSocket::SockExit(void)
{
	return 1;
}
int CSocket::SockStart(void)
{
	return 1;
}

char* CSocket::myhost()
{
	static char buf[16];
	gethostname(buf, 16);
	return buf;
}

bool CSocket::udpMulicastConnected(){
	return proc == UDP_MULTICAST;
}
