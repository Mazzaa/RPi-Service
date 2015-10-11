#ifndef RPI_H
#define RPI_H

//...Linux headers
/*
  	RPI Discovery Testing
*/
#include <stdio.h> //printf
#include <string.h> //memset
#include <stdlib.h> //exit(0);

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <net/if.h>
#include <netinet/in.h>

#include <execinfo.h> 		//...EXEPTION HANDLER
#include <sys/syscall.h>

#include <fcntl.h>
#include <signal.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>  
#include <semaphore.h>  /* Semaphore */		

#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <errno.h>
#include <time.h>
#include <math.h>

#define max_rpi(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; } )
#define min_rpi(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; } )

//#define max(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; } )
//#define min(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; } )

//...Project Deifines
#define PROJECT_SERIAL (int)0x1555 //...C&C Ping
#define RPI_SERIAL 0xFAB4 //...Unique serial for the PI ( NOT FOR PING )

#define RPI_NET_PING 0x00 			//..HELLO : "Anyone Home?" ( IP :  AND)
#define RPI_NET_PONG 0x01 			//..REPLY : "Im Home ID "
#define RPI_NET_HEARTBEAT 0x02 		//...Heart Beat ( Interval to let them know their alive )
#define RPI_NET_HEAREDBEAT 0x03		//...Hear beat was heard

//...Packet relay ( TCP Prefered );
#define RPI_NET_RELAY_INIT 0x90		//...Init Packet relay ( {TCP|IP}:S_IP:S_PORT:D_IP:D_PORT )
#define RPI_NET_RELAY_CLOSE 0x91 	//...Close Packet relay ( RELAY ID : UNIQUE SERIAL );
#define RPI_NET_RELAY_PACKET 0x92 	//...Relay a pack to specified details ( RELAY ID : PACKET-ID : PACKET SIZE : [DATA-HER] )
#define RPI_NET_RELAY_STATUS 0x93	//...Reply packet about a packet ( RELAY ID : PACKET-ID : STATUS{ACK|RST})

#define RPI_NET_RELAY_ACK 0x94		//...Packet was successfuly relayed ( RELAY ID: PACKET ID SENT )
#define RPI_NET_RELAY_RST 0x95		//...Packet was Packet couldn't  be sent, Re-sent please ( Used when we have a missing packet id )
#define RPI_NET_RELAY_SYN 0x96		//...Sync the packet 

#define NET_TTL 250 ///...Active connect TTYL for packet
#define NET_TIMEOUT 2000 //...2000 miliseconds timeout

//...Serial defines
#define SERIAL_ID_UNKNOW 0
#define SERIAL_ID_RPI 1
#define SERIAL_ID_CC 2

#define BUFF_SIZE_S 64
#define BUFF_SIZE_M	128
#define BUFF_SIZE_L 256
#define BUFF_SIZE_X	512
#define BUFF_SIZE_Y 1024
#define BUFF_SIZE_Z 2048

#define SERVER_PORT 	22770   //#IN-COMING - the port on which to listen for incoming data ( RPI in's)
#define SERVER_PORT_OUT 21770	//#OUT-GOING - Port of outgoing information ( RPI's Sending from main thread)
#define SERVER_MULTCAST_ADDR 		"239.255.60.60"
#define SERVER_MULTCAST_ADDR_RPI 	"239.255.60.50"
#define SERVER_CANBUS_PORT 		4876

#define CANUDP_BUS_ID				0x54726974697560

/*
	#########################################################################
	#																		#
	#					-- BEGIN COPYRIGHT SECTION --						#
	#																		#
	#########################################################################
	TRITIUM CAN-ETHERNET INTERFACE LIBRARY v1.0
 * Copyright (c) 2011, Tritium Pty Ltd.  All rights reserved.
*/
/*************************************************************************//**
 * htonll - big endian/little endian byte swapping macros for
 * 64-bit (long long) values
 ****************************************************************************/
#ifndef htonll
    #define htonll(a)                              \
        ((((a) >> 56) & 0x00000000000000ffull) |   \
         (((a) >> 40) & 0x000000000000ff00ull) |   \
         (((a) >> 24) & 0x0000000000ff0000ull) |   \
         (((a) >>  8) & 0x00000000ff000000ull) |   \
         (((a) <<  8) & 0x000000ff00000000ull) |   \
         (((a) << 24) & 0x0000ff0000000000ull) |   \
         (((a) << 40) & 0x00ff000000000000ull) |   \
         (((a) << 56) & 0xff00000000000000ull))
#endif
/*************************************************************************//**
 * ntohll - big endian/little endian byte swapping macros for
 * 64-bit (long long) values
 ****************************************************************************/
#ifndef ntohll
    #define ntohll(a)    htonll((a))
#endif

typedef unsigned long UInt32;		///< Unsigned 32bit integer
typedef unsigned long long UInt64;	///< Unsigned 64bit integer
typedef unsigned short UInt16;		///< Unsigned 16bit integer
typedef unsigned char UInt8;		///< Unsigned 8bit integer
typedef unsigned char byte;			///< A data byte

/*
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	TRITIUM CAN-ETHERNET INTERFACE LIBRARY v1.0
 	Copyright (c) 2011, Tritium Pty Ltd.  All rights reserved.
	#########################################################################
	#																		#
	#					-- END COPYRIGHT SECTION --							#
	#																		#
	#########################################################################
*/

//...MYSQL CONSTANTS
#define MYSQL_DEFAULT_IP "127.0.0.1" //"gnar.local"
#define MYSQL_DEFAULT_PORT 3306

#define MYSQL_USER	"solar"
#define MYSQL_PASS	"solar"

#define MYSQL_DEFAULT_DB "main"
#define MYSQL_DB_PI	"pi"
#define MYSQL_DB_RECORDS "records"
#define MAX_MYSQL_CONNECTIONS 8

//...Default SQL Template
#define SQL_CREATE_TABLE "CREATE TABLE"
#define SQL_DROP_TABLE_IF "DROP TABLE IF EXISTS"

/*
	MYSQL - DEFAULT SETUP for PI table:
		For the pi table we need :
		id ( INTERGER - Unique serial id )
		name ( STRING(255) - Hostname of the device );
		ip Address ( STRING 16 (123.567.891.012 ))
		port - ([MYSQL - SMALLINT] [CPP - UNSIGNED SHORT ])
		services - STRING (255) <- SERVICES are seperated by '|' delimter eg: SSH|MYSQL|WWW
*/
#define SQL_PI_TABLE_DEFAULT "(id INT UNSIGNED PRIMARY KEY , name VARCHAR(255) , ip VARCHAR(16) , port SMALLINT , services VARCHAR(255), ping INT )"
#define SQL_PI_FIELDS_INSERT "(id,name,ip,port,services,ping)" 

//...RPI Services
#define SERV_SSH "SSH"
#define SERV_WWW "WWW"
#define SERV_SQL "SQL"
#define SERV_RPI "RPI"
#define SERV_REC "REC"

#define AM_SERVER 1 //...SERVER LOCK
#define AM_CLIENT 2 //...Client 

#define FILE_SERVER_PID "/var/run/RPi.pid"

//...Define
#define CPU_ID_SERVICE 3
#define CPU_ID_CAN_LOGGER 2
#define CPU_ID_DATA_PROCCESSOR 1
#define CPU_ID_SYSTEM 0

#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

//....STD Libarays
using namespace std;

//....MYSQL Port

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/metadata.h>

//...Windows port
#include "win_port.h"


//...Project build tool headers
#include "mem.h"				// mem.cpp
#include "sock.h"				// sock.cpp
#include "tools.h"				// tools.cpp | md5.cpp
#include "Timer.h"

//...Project header
#include "raspberrypi.h"		// : raspberrypi.cpp
#include "core.h"				// : core.cpp
#include "database.h"			// : database.cpp

#include "pi_handler.h" 		// : raspberrypi_sql.cpp
#include "service.h"			// : RPi Service thread

/*
	CAN Thread Headers 
		- CanLogger
			-Dictonary
			-CanPacket
*/

#include "canpacket.h"
#include "can_logger.h"
#include "canlogger_dictonary.h"


inline int randrange ( int min , int max ) {
	return rand()%(max-min + 1) + min;
}

//...Static global
static pthread_mutexattr_t				gMemoryShare;
static CRaspberryPi 					gPi;
static CZCore							gCore;
static CRPiService						gService;
static CCanLoggerDictonary 				ghex_id_data;
static CCanLogger       				gCanLogger;

static std::vector<CRaspberryPi*> 		gPiList;
static pthread_mutex_t 					gPiListLock = PTHREAD_MUTEX_INITIALIZER;
static CSocket 							gSocketCore;

static CPiSQLHandler* 					qPiHandler;



//...DATA QUEUE
static pthread_mutex_t 					dataQueueAlphaMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t 					dataQueueBravoMutex = PTHREAD_MUTEX_INITIALIZER;
static std::vector<CanPacket*> 			dataQueueAlpha;
static std::vector<CanPacket*> 			dataQueueBravo;

#endif