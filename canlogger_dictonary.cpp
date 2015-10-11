#include "rpi.h"

//...Constructors
CCanLoggerDictonary::CCanLoggerDictonary(){

}
CCanLoggerDictonary::~CCanLoggerDictonary(){

}

//...Start/Stop
bool CCanLoggerDictonary::initDictonary(){
	hex_id_data.clear();
	return true;
}
bool CCanLoggerDictonary::stopDictonary(){

	return true;
}

int CCanLoggerDictonary::getRecordCount (){
	return hex_id_data.size();
}


bool CCanLoggerDictonary::checkExist ( int id )		//...Check for hex id
{
	//...Look for ID:
	 std::map<int,sDictonaryItem *>::iterator it;
	 it = hex_id_data.find(id);
  	if (it != hex_id_data.end())
  		return true;
  	else 
  		return false;
}

bool CCanLoggerDictonary::getRecord ( int id , sDictonaryItem * record ){

}
char* CCanLoggerDictonary::getRecordName ( int id ){
	//...Safe chech
	if (!checkExist(id))return NULL;

	//...Get the record
	std::map<int,sDictonaryItem *>::iterator it;
	it = hex_id_data.find(id);
	sDictonaryItem * get = NULL;(sDictonaryItem *)hex_id_data[id];
	return get->getDataName();
}

bool CCanLoggerDictonary::addDictonaryRecord ( sDictonaryItem * record ) //...Add new dictonary record
{
	hex_id_data.insert ( std::pair<int,sDictonaryItem * >( record->getHexID() , record ) );
	return true;
}