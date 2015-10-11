#include "rpi.h"

/*
	UInt64 BUS_ID;
	UInt64 CLIENT_ID;
	UInt32 hexId;

	char flags;
	char length;

	char data [255];

	8	8 Bytes Bus ID ( INT (4BYTES) ())
	16	8 Bytes Client ID
	20	4 Bytes 

	21	1 Byte flag:
	22	1 Byte length: 

	//..HEADER

*/

//...Constructor
CanPacket::CanPacket ( CBuffer * in ) 	//# IN : Import packet
{
	//...UNPACK PACKETS
	if ( in == NULL )return;

	//..Chech header
	if ( in->bytesleft() < 22 )return;
	//...Check size
	in->StreamRead ( &BUS_ID 	, sizeof ( UInt64 ));
	in->StreamRead ( &CLIENT_ID , sizeof ( UInt64 ));
	in->StreamRead ( &hexId 	, sizeof ( UInt32 ));

	//...Read bytes
	flags = in->readbyte();
	length = in->readbyte();

	//...Read out data
	if ( length != in->bytesleft() ){
		printf("[WARNING] BYTE MISS MATCH : %i %i\n", length , in->bytesleft() );
	}

	//...Read out data
	in->StreamRead ( &CAN_DATA , length );

}
CanPacket::CanPacket ( UInt32 id , CBuffer * out ) //# OUT DATA
{
	//...PACK THE PACKET
	char localData[BUFF_SIZE_L];
	int size = out->bytesleft();
	out->StreamRead ( &localData , size );
	out->clear();

	   // - Bus Header
	UInt64 wrBUS_ID = 0x0054726974697560,
		   virtualUId = 0x000000000000000D,
		   wrFullID = 0x0054726974697560 & 0x000000000000000D;
		   wrFullID = htonll(wrFullID);
    out->StreamWrite ( &wrFullID , sizeof( UInt64 ) );

    // - Client Identification
    UInt64 wrClient_ID = htonll(0xAABBCCDDEEFF0000);
    out->StreamWrite ( &wrClient_ID , sizeof( UInt64 ) ) ;

    // - Packet identification
    UInt32 wrHexId = id;
    out->writeuint ( __bswap_32 ( wrHexId ) );

    // - Fields ( FLags then length )
    out->writebyte( flags );

    //...Write : Buffer
    out->writebyte ( (char) min(size,255) );
    out->StreamWrite ( &localData , size );
}

//...Get functions
UInt32 	CanPacket::getID ( ){
	return hexId;
}
char 	CanPacket::getLength()
{
	return length;
}

//....Data
//...Copy internal data to the buffer
//	CAN-PACKET --> OUT BUFFER
void CanPacket::getData ( CBuffer * out )
{
	//...Get the data out
	if ( out == NULL )return;

	//...Append data : Appent our data out
	int size =  static_cast<int>(length);
	out->StreamWrite ( &CAN_DATA , size ); 
}

//...Set the can packet datax
void CanPacket::setData ( CBuffer * in )
{
	//...Set packet data to buffer content
	if ( in == NULL )return;

	//...Get data out
	int size = in->bytesleft();
	in->StreamRead ( &CAN_DATA , min ( 255 , size));
}