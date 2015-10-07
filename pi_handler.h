#pragma once

class CPiSQLHandler : public CMySQL {
	//...Static prefix
	static char prefix[BUFF_SIZE_M];

	//...SQL QUERY EXECUTE
	bool executeQuery ( char * mysql_Query );

	//...Get connector


public:
	 CPiSQLHandler ();
	 ~CPiSQLHandler();

	 //...Init Handler
	 bool initHandler ();

	 bool createPiTable ();
	 bool resetPiTable ();
	 bool dropPiTable();

	 //...Pi functions
	 bool registerPi ( CRaspberryPi * pi );
	 bool registerPi ( char* ip , unsigned short port , int serial , char * name );

	 //...Pi functions
	 bool checkPi ( CRaspberryPi * pi );
	 bool checkPi ( char* ip , unsigned short port , int serial );

	 //...Derg pi
	 	 //...Pi functions
	 bool removePi ( CRaspberryPi * pi );
	 bool removePi ( char* ip , unsigned short port , int serial );

	 //...Get Pi
	 int getPiCount ( );
	 CRaspberryPi * getPi ( int index );
	 void getPi ( int index , CRaspberryPi * pi );

	 //...Threading wise : Set your own connector
};