#pragma once 

/*
	Can packet : Abstract based off the the tritium packet design; 

	This is a basic constructor for can packet reciveving :
		For the packet we will primarly be using this for receving

		PACKET CONSTANTS
			BUS_ID is 		0x0054726974697560 
			VIRTUAL CIRCUT 	0x000000000000000D ^ | ( BUS_ID & MASK )
			CLIENTID		0xAABBCCDDEEFF0000	
*/

class CanPacket
{
protected:
	//...Private data
	UInt64 BUS_ID;
	UInt64 CLIENT_ID;
	UInt32 hexId;

	char flags;
	char length;

	char CAN_DATA [BUFF_SIZE_M];

public:
	//...Constructor
	CanPacket ( CBuffer * in ); 	//# IN : Import packet
	CanPacket ( UInt32 id , CBuffer * out ); //# OUT DATA

	//...Get functions
	UInt32 	getID ( );
	char 	getLength();	//...Packets limted to 255  bytes;

	//....Data
	void getData ( CBuffer * out );	//...Copy internal data to the buffer
	void setData ( CBuffer * in ); //...Copy all data into packet
};
