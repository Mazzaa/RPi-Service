#pragma once

struct _sConnectors {
	sql::Connection * con;
	bool inUse;
};

//...Extend the class is the better idea
class CMySQL {
	protected:
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *prep_stmt;
		sql::DatabaseMetaData *dbcon_meta;

		//...Lets use 8 connectors
		_sConnectors connector[8];

		void initConnectors ();
		void freeConnector ( sql::Connection * );
		void updateConnectors();

		static char prefix[BUFF_SIZE_L];

	public:
		CMySQL ();

		bool initConnector ( );
		bool destroyConnector ( );

		void displaySQLException ( sql::SQLException &e , char * __function ){ 
			printf ( "\t Error: SQLException " __FILE__ " \n");
			printf ( "\t( %s ) " , __function  );
  			printf ( "\t : ERROR %s " , e.what());
			printf ( "\t MySQL error code: %i \n" , e.getErrorCode());
			printf ( "\t MysQL server State: %s\n", e.getSQLStateCStr());		
 		}

 		//...Get functions
 		sql::Connection * getCon(); //...Return a free connector

};
