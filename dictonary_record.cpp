#include "rpi.h"

/*
	int id; //...This is coded in hex;
	char hexStr[BUFF_SIZE_S]; //..String representation 
	char dataName[BUFF_SIZE_L];

	std::vector < sDictonaryField * > myFields;
*/

sDictonaryItem::sDictonaryItem ( int hexId , char * name ){
	//...Setup
	this->id = hexId;
	strcpy (dataName , name );
	myFields.clear();
	//# UNCOMMENT TO DEBUG IMPORTED HEX ID's
	//printf("[%#03x] Imported %s ... \n", hexId , );
}
/*
	//...Structure
	struct sDictonaryField {
		char FEILD 	[ BUFF_SIZE_S ];
		char TYPE	[ BUFF_SIZE_S ];
		bool endian;					//...Can data can be BIG or LITTLE ENDIAN
		int size;
	};
*/

//...Identifier
int sDictonaryItem::getHexID( ){
	return id;
}
char* sDictonaryItem::getDataName ( ){
	return dataName;
}

//...Feilds
void sDictonaryItem::addField ( char* name , char* type , int bitSize ){
	//...Add new field
	sDictonaryField * newF = new sDictonaryField();
	strcpy ( newF->FEILD ,  name );
	strcpy ( newF->TYPE ,  type );
	newF->size = bitSize;

	//...Add record
	myFields.insert ( myFields.end() , newF );
}
void sDictonaryItem::delField ( char* name , char* type , int bitSize ){

}

int sDictonaryItem::getFieldCount (){
	return (int)myFields.size();
}
sDictonaryField * sDictonaryItem::getField ( int index ){
	return NULL;
}
void sDictonaryItem::getField ( int index , sDictonaryField * out ){
	return;
}
char* sDictonaryItem::getFieldName ( int index ){
	return NULL;
}
int sDictonaryItem::getFieldSize ( int index ){
	return NULL;
}