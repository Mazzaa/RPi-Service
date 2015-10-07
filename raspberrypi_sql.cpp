#include "rpi.h"

char CPiSQLHandler::prefix[BUFF_SIZE_M];


CPiSQLHandler::CPiSQLHandler (){
	//...Check driver:]
	strcpy ( prefix , "[MYSQL]: ");
	initConnector();

}
CPiSQLHandler::~CPiSQLHandler(){
	//...Stop the handler
	destroyConnector();

	try {

	}catch ( sql::SQLException &e ) {
		displaySQLException ( e , "CPiSQLHandler::~CPiSQLHandler");
	}
}

//...USE class 'res' to get the res
bool CPiSQLHandler::executeQuery ( char * mysql_Query ){
	try {
		stmt = con->createStatement();
		stmt->execute( mysql_Query );
		delete stmt;
	}catch ( sql::SQLException &e ) {
		displaySQLException ( e , "CPiSQLHandler::~CPiSQLHandler");
		return false;
	}
	return true;
}

bool CPiSQLHandler::initHandler () {
	//...Start handler
	char connectorStr[BUFF_SIZE_X];
	sprintf ( connectorStr , "tcp://%s:%i" , MYSQL_DEFAULT_IP , MYSQL_DEFAULT_PORT );

	try {
		if ( driver == NULL ){
			initConnector();
		}
		//...Connect
		this->con = driver->connect( connectorStr , MYSQL_USER , MYSQL_PASS );
		/* Connect to the MySQL test database */
		 this->con->setSchema( MYSQL_DEFAULT_DB );
	}catch ( sql::SQLException &e ) {
		displaySQLException ( e , "CPiSQLHandler");
		printf ( "[ERROR] MYSQL CONNECT TO DATABASE : %s FAILED\n" , MYSQL_DEFAULT_IP );
		return false;
	}
	printf ( "%s CONNECTED TO %s \n" , prefix , MYSQL_DEFAULT_IP );
	return resetPiTable();
}

bool CPiSQLHandler::createPiTable (){
	//...Generate buffer
	char connectorStr[BUFF_SIZE_X];
	sprintf ( connectorStr , "%s %s %s", SQL_CREATE_TABLE , MYSQL_DB_PI , SQL_PI_TABLE_DEFAULT );
	printf("%s 'Pi' TABLE CREATE\n", prefix );
	return executeQuery ( connectorStr );
}

bool CPiSQLHandler::resetPiTable (){
	//...Drop the table then recreate the table
	return (dropPiTable()?createPiTable():false);
}

bool CPiSQLHandler::dropPiTable(){
	//...Generate buffer
	char connectorStr[BUFF_SIZE_X];
	sprintf ( connectorStr , "%s %s", SQL_DROP_TABLE_IF , MYSQL_DB_PI );
	printf("%s 'Pi' TABLE DROPPED\n", prefix );
	return executeQuery ( connectorStr );
}

//...Pi functions
bool CPiSQLHandler::registerPi ( CRaspberryPi * pi ){
	/*
			//...Gets
	char * 			getIpAddress ();
	unsigned short 	getPort();
	int 			getSerial ();
	char* 			getMyName();
	*/
	try {
		//...Prepared statement
		prep_stmt = con->prepareStatement("INSERT INTO pi(id, name,ip,port,services) VALUES (?, ?, ?, ?, ?)");
		prep_stmt->setInt		( 1 , pi->getSerial() );
		prep_stmt->setString	( 2 , pi->getMyName() );
		prep_stmt->setString 	( 3 , pi->getIpAddress() );
		prep_stmt->setInt 		( 4 , pi->getPort() );
		prep_stmt->setString 	( 5 , "SSH|PHP|RPI" );
		prep_stmt->execute();
		delete prep_stmt;
	}catch ( sql::SQLException &e ) {
		if ( e.getErrorCode() <= 0 ) return true;
		displaySQLException ( e  , "CPiSQLHandler::registerPi" );	
		return e.getErrorCode() == 0;
	}

	return true;
}
bool CPiSQLHandler::registerPi ( char* ip , unsigned short port , int serial , char* name ){
	CRaspberryPi * p = new CRaspberryPi ( ip , port , serial , name );
	if ( registerPi ( p ) ){
		delete p;
		return true;
	}
	delete p;
	return false;
}

//...Pi functions
bool CPiSQLHandler::checkPi ( CRaspberryPi * pi ){
	static pthread_mutex_t lock;
	pthread_mutex_lock(&lock);
	//...Check the pi
	char queryStr[BUFF_SIZE_X];
	sprintf ( queryStr , "SELECT id,ip FROM %s WHERE id=%i;" , MYSQL_DB_PI , pi->getSerial() );
	bool ret = false;
	try{
		//driver
		//...Check connector
		if ( this->driver == NULL ){
			printf("[ERROR] MYSQL DRIVER EXCEPTION\n" );
		}
		if ( this->con == NULL ){
			printf("[ERROR] MYSQL CONNECTOR EXCEPTION\n" );
		}

		stmt = con->createStatement();
		res = stmt->executeQuery(queryStr);
		while (res->next()) {
			//...Check id
			if ( res->getInt("id") == pi->getSerial() ){
				ret = true;
			}
		}
		delete res;
		delete stmt;
	}catch ( sql::SQLException &e ) {
		delete res;
		delete stmt;
		displaySQLException ( e  , "CPiSQLHandler::checkPi" );	
		pthread_mutex_unlock(&lock);
		return false;
	}
	pthread_mutex_unlock(&lock);
	return ret;
}
bool CPiSQLHandler::checkPi ( char* ip , unsigned short port , int serial ){
	CRaspberryPi * p = new CRaspberryPi ( ip , port , serial , "" );
	return checkPi (p);
}

//...Derg pi
	 //...Pi functions
bool CPiSQLHandler::removePi ( CRaspberryPi * pi ){
	char removeStr[BUFF_SIZE_X];

	return true;
}
bool CPiSQLHandler::removePi ( char* ip , unsigned short port , int serial ){

	return true;
}

//...Get Pi
int CPiSQLHandler::getPiCount ( ){
	int piCount = 0;

	try {
		stmt = con->createStatement();
		res = stmt->executeQuery("SELECT id, label FROM test ORDER BY id ASC");
		while (res->next()) {
			piCount++;
		}

		delete res;
	}catch ( sql::SQLException &e ) {
		delete res;
		delete stmt;
		displaySQLException ( e  , "CPiSQLHandler::getPiCount" );	
		return false;
	}
	return piCount;
}
CRaspberryPi * CPiSQLHandler::getPi ( int index ){

	return NULL;
}
void CPiSQLHandler::getPi ( int index , CRaspberryPi * pi ){

}