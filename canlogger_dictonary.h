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
	int size;
};

class sDictonaryItem {
	int id; //...This is coded in hex;
	char hexStr[BUFF_SIZE_S]; //..String representation 
public:
	sDictonaryItem ( int hexId );

	//...Feilds
	void addField ( char* name , char* type , int bitSize );
	void delField ( char* name , char* type , int bitSize );

	int getFieldCount ();	//...Number of fields
	
	sDictonaryField * getField ( int index );
	void getField ( int index , sDictonaryField * out );


};

//....Structure
class CCanLoggerDictonary {

	//...Dicotnary store
public:
	//...Constructors
	CCanLoggerDictonary();
	~CCanLoggerDictonary();

	//...Start/Stop
	bool initDictonary();
	bool stopDictonary();

	//...Set import
	void setDictonaryHardCoded();	//...Set to use dictonary hard coded
	void setDictonaryImportFIle();	//...Set to use imported dictonary

	//...Import
	bool setImportFile ( char * dictonary );		//...Set the file we are going to inport
	bool initImportFile();	//...Start processing the file for inport


};