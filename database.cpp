#include "rpi.h"

char CMySQL::prefix[BUFF_SIZE_L];

//...Database class
CMySQL::CMySQL (){
	strcpy( prefix , "[MYSQL]: ");
	initConnector();
}

bool CMySQL::initConnector ( ){
	//...Get connector
	if ( driver == NULL ){
		driver = get_driver_instance();
		driver->threadInit();
	}

	//...Get meta 
	//dbcon_meta = con -> getMetaData();

	//...Print info
	//printf ("%s Version: %i.%i.%i \n" , driver->getMajorVersion() ,
	//		 driver->getMinorVersion() , driver->getPatchVersion() );

	return driver != NULL;
}

bool CMySQL::destroyConnector ( ){
	//...Get connector
	if ( driver != NULL ){
		driver = NULL;
	}
	return true;
}

/*
	struct _sConnectors {
		sql::Connection * con;
		bool inUse;
	};
*/

void CMySQL::initConnectors (){
	//...Start handler
	for ( int i=0;i<MAX_MYSQL_CONNECTIONS;i++){
		connector[i].con = NULL;
		connector[i].inUse = false;
	}
	char connectorStr[BUFF_SIZE_X];
	sprintf ( connectorStr , "tcp://%s:%i" , MYSQL_DEFAULT_IP , MYSQL_DEFAULT_PORT );
}
void CMySQL::CMySQL::freeConnector ( sql::Connection * ){

}
void CMySQL::updateConnectors(){

}
sql::Connection * CMySQL::getCon() //...Return a free connector
{

	return NULL;
}