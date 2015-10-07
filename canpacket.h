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
	//...Packet headers
	UInt64 busId;			//...BUS ID: 0x0054726974697560 
	UInt64 senderId;
	UInt32 id;

	//...Can packet flags
	bool bridgeHb;
	bool extended;
	bool rtr;

	byte length;
	void init(UInt32 id, bool extended, bool rtr, byte length, UInt64 data);
	void init(UInt32 id, bool extended, bool rtr, byte length, byte* data);
public:
	//...Constructor
	CanPacket(UInt32 id, bool extended, bool rtr, byte length, UInt64 data);
	CanPacket(UInt32 id, bool extended, byte length, UInt64 data);
	CanPacket(UInt32 id, bool extended, bool rtr, byte length);
 	CanPacket(UInt32 id, bool extended, bool rtr, byte length, byte* data);
	CanPacket(UInt32 id, bool extended, byte length, byte* data);

	//...Get functions
	UInt32 getId();
	bool isExtended();
	bool isRTR();
	UInt64 getData();
	UInt64 getDataValue();
	byte* getDataArray();
	byte getLength();
};
