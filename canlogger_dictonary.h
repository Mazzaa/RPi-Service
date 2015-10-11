#pragma once 

/*
	Can Logger dictonary

	Dictonary options:
		- Hard coded ( Static : easy memory acces );
		- Import ( Processing )
			[HEX ID : 32Bit INT]
			[DATA] <- STRUCT
				FOR EACH MEMBER
					FEILD - STRING (255)
					Datatyope - STING (64){"INT","BOOLEAN","STRING","LONG","FLOAT","DOUBLED","BINARY" }
					SIZE - INT (4BYtes) This int represents the size in bytes

				NEXT
			Each ID is seperated by new line 
			0x520:
			HEX:DATA:{REPEAT: [FEILD:TYPE:SIZE]}

*/

//...Structure
struct sDictonaryField {
	char FEILD 	[ BUFF_SIZE_S ];
	char TYPE	[ BUFF_SIZE_S ];
	bool endian;					//...Can data can be BIG or LITTLE ENDIAN
	int size;
};

class sDictonaryItem {
	int id; //...This is coded in hex;
	char hexStr[BUFF_SIZE_S]; //..String representation 
	char dataName[BUFF_SIZE_L];

	std::vector < sDictonaryField * > myFields;

public:
	sDictonaryItem ( int hexId , char * name );

	//...Identifier
	int getHexID( );
	char* getDataName ( );

	//...Feilds
	void addField ( char* name , char* type , int bitSize );
	void delField ( char* name , char* type , int bitSize );

	int getFieldCount ();	//...Number of fields
	
	sDictonaryField * getField ( int index );
	void getField ( int index , sDictonaryField * out );
	char* getFieldName ( int index );
	int getFieldSize ( int index );
};

//....Structure
class CCanLoggerDictonary {

	//...Dicotnary store
	std::map<int,sDictonaryItem*> hex_id_data;
public:
	//...Constructors
	CCanLoggerDictonary();
	~CCanLoggerDictonary();

	//...Start/Stop
	bool initDictonary();
	bool stopDictonary();


	void initImportHardCoded();		//...Imports hard coded dictonary

	//...Tools
	int getRecordCount ();

	bool checkExist ( int id );		//...Check for hex id

	bool addDictonaryRecord ( sDictonaryItem * record ); //...Add new dictonary record

	//...Dictonary lookup
	bool getRecord ( int id , sDictonaryItem * record );
	char* getRecordName ( int id );
};