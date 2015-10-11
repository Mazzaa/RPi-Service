#include "rpi.h"

void CCanLoggerDictonary::initImportHardCoded( )
{
	sDictonaryItem * newHexID;
	// HEX: 0x0 NAME: CAN_Ethernet_Bridge
	newHexID = new sDictonaryItem (0x0 , "CAN_Ethernet_Bridge");
	newHexID->addField("Current_CAN_Bitrate","uint",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("CAN_Bridge_MAC_Address"," hex",48); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x0ADD FAIL");
	}

	// HEX: 0x400 NAME: Identification_Information
	newHexID = new sDictonaryItem (0x400 , "Identification_Information");
	newHexID->addField("Tritium_ID","bytes",4); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Serial_Number"," uintle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x400ADD FAIL");
	}

	// HEX: 0x401 NAME: Status_Information
	newHexID = new sDictonaryItem (0x401 , "Status_Information");
	newHexID->addField("LF_Reserved","bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("IPM_Temp_or_Motor_Temp"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Bus_Voltage_Lower_Limit"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Bus_Voltage_Lower_Limit"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Bus_Current"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Velocity"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Motor_Current"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Output_Voltage_PWM"," bin",9); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Desaturation_Fault"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("15V_Rail_Under_Voltage"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Config_Read_Error"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Watchdog_Caused_Last_Reset"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Bad_Motor_Position_Hall_Sequence"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("DC_Bus_Over_Voltage"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Software_Over_Current"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Hardware_Over_Current"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("EF_Reserved"," bin",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Active_Motor"," uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Transmit_Error"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Receive_Error"," uintle",8); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x401ADD FAIL");
	}

	// HEX: 0x402 NAME: Bus_Measurement
	newHexID = new sDictonaryItem (0x402 , "Bus_Measurement");
	newHexID->addField("Bus_Voltage","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Bus_Current"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x402ADD FAIL");
	}

	// HEX: 0x403 NAME: Velocity_Measurement
	newHexID = new sDictonaryItem (0x403 , "Velocity_Measurement");
	newHexID->addField("Motor_Velocity","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Vehicle_Velocity"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x403ADD FAIL");
	}

	// HEX: 0x404 NAME: Phase_Current_Measurement
	newHexID = new sDictonaryItem (0x404 , "Phase_Current_Measurement");
	newHexID->addField("Phase_B_Current","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Phase_C_Current"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x404ADD FAIL");
	}

	// HEX: 0x405 NAME: Motor_Voltage_Vector_Measurement
	newHexID = new sDictonaryItem (0x405 , "Motor_Voltage_Vector_Measurement");
	newHexID->addField("V_q","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("V_d"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x405ADD FAIL");
	}

	// HEX: 0x406 NAME: Motor_Current_Vector_Measurement
	newHexID = new sDictonaryItem (0x406 , "Motor_Current_Vector_Measurement");
	newHexID->addField("I_q","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("I_d"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x406ADD FAIL");
	}

	// HEX: 0x407 NAME: Motor_BackEMF_Measurement_/_Prediction
	newHexID = new sDictonaryItem (0x407 , "Motor_BackEMF_Measurement_/_Prediction");
	newHexID->addField("BEMF_q","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("BEMF_d"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x407ADD FAIL");
	}

	// HEX: 0x408 NAME: 15V_Voltage_Rail_Measurement
	newHexID = new sDictonaryItem (0x408 , "15V_Voltage_Rail_Measurement");
	newHexID->addField("Reserved","bin",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("15V_Supply"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x408ADD FAIL");
	}

	// HEX: 0x409 NAME: 3.3V_and_1.9V_Voltage_Rail_Measurement
	newHexID = new sDictonaryItem (0x409 , "3.3V_and_1.9V_Voltage_Rail_Measurement");
	newHexID->addField("1.9V_Supply","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("3.3V_Supply"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x409ADD FAIL");
	}

	// HEX: 0x40a NAME: MC_RESERVED_1
	newHexID = new sDictonaryItem (0x40a , "MC_RESERVED_1");
	newHexID->addField("reserved","bin",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("reserved"," bin",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x40aADD FAIL");
	}

	// HEX: 0x40b NAME: IPM_Heatsink_and_Motor_Temperature_Measurement
	newHexID = new sDictonaryItem (0x40b , "IPM_Heatsink_and_Motor_Temperature_Measurement");
	newHexID->addField("Motor_Temp","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("IPM_Heatsink_Temp"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x40bADD FAIL");
	}

	// HEX: 0x40c NAME: IPM_DSP_Board_Temperature_Measurement
	newHexID = new sDictonaryItem (0x40c , "IPM_DSP_Board_Temperature_Measurement");
	newHexID->addField("DSP_Board_Temp","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Reserved"," bin",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x40cADD FAIL");
	}

	// HEX: 0x40d NAME: MC_IPM_RESERVED_1
	newHexID = new sDictonaryItem (0x40d , "MC_IPM_RESERVED_1");
	newHexID->addField("reserved","bin",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("reserved"," bin",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x40dADD FAIL");
	}

	// HEX: 0x40e NAME: Odometer_and_Bus_AmpHours_Measurement
	newHexID = new sDictonaryItem (0x40e , "Odometer_and_Bus_AmpHours_Measurement");
	newHexID->addField("Odometer","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("DC_Bus_AmpHours"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x40eADD FAIL");
	}

	// HEX: 0x417 NAME: Slip_Speed_Measurement
	newHexID = new sDictonaryItem (0x417 , "Slip_Speed_Measurement");
	newHexID->addField("Slip_Speed","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("reserved"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x417ADD FAIL");
	}

	// HEX: 0x501 NAME: Motor_Drive_Command
	newHexID = new sDictonaryItem (0x501 , "Motor_Drive_Command");
	newHexID->addField("Desired_Velocity","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Desired_Current"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x501ADD FAIL");
	}

	// HEX: 0x502 NAME: Motor_Power_Command
	newHexID = new sDictonaryItem (0x502 , "Motor_Power_Command");
	newHexID->addField("Reserved","bin",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Desired_Bus_Current"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x502ADD FAIL");
	}

	// HEX: 0x505 NAME: DC_SWITCH
	newHexID = new sDictonaryItem (0x505 , "DC_SWITCH");
	newHexID->addField("Brake_Switch","bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Start_Switch"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Run_Switch"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Accessories_Switch"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Drive_Switch"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Regen_Switch"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Neutral_Switch"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Reverse_Switch"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Reverse_Switch_Fault"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Brake_Switch_Fault"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("CAN_Switch_Fault"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Accelerator_Switch_Fault"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Spare_Switch_3"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Spare_Switch_2"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Spare_Switch_1"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Fuel_door_Switch"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Unknown1"," uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Unknown2"," uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Flags"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("State"," uintle",8); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x505ADD FAIL");
	}

	// HEX: 0x510 NAME: DIU_REQUEST_1
	newHexID = new sDictonaryItem (0x510 , "DIU_REQUEST_1");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x510ADD FAIL");
	}

	// HEX: 0x511 NAME: DIU_REQUEST_2
	newHexID = new sDictonaryItem (0x511 , "DIU_REQUEST_2");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x511ADD FAIL");
	}

	// HEX: 0x512 NAME: DIU_REQUEST_3
	newHexID = new sDictonaryItem (0x512 , "DIU_REQUEST_3");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x512ADD FAIL");
	}

	// HEX: 0x513 NAME: DIU_REQUEST_4
	newHexID = new sDictonaryItem (0x513 , "DIU_REQUEST_4");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x513ADD FAIL");
	}

	// HEX: 0x514 NAME: DIU_REQUEST_5
	newHexID = new sDictonaryItem (0x514 , "DIU_REQUEST_5");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x514ADD FAIL");
	}

	// HEX: 0x515 NAME: DIU_REQUEST_6
	newHexID = new sDictonaryItem (0x515 , "DIU_REQUEST_6");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x515ADD FAIL");
	}

	// HEX: 0x516 NAME: DIU_REQUEST_7
	newHexID = new sDictonaryItem (0x516 , "DIU_REQUEST_7");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x516ADD FAIL");
	}

	// HEX: 0x517 NAME: DIU_REQUEST_8
	newHexID = new sDictonaryItem (0x517 , "DIU_REQUEST_8");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x517ADD FAIL");
	}

	// HEX: 0x518 NAME: DIU_REQUEST_9
	newHexID = new sDictonaryItem (0x518 , "DIU_REQUEST_9");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x518ADD FAIL");
	}

	// HEX: 0x519 NAME: DIU_REQUEST_10
	newHexID = new sDictonaryItem (0x519 , "DIU_REQUEST_10");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x519ADD FAIL");
	}

	// HEX: 0x520 NAME: DIU_REPLY_1
	newHexID = new sDictonaryItem (0x520 , "DIU_REPLY_1");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x520ADD FAIL");
	}

	// HEX: 0x521 NAME: DIU_REPLY_2
	newHexID = new sDictonaryItem (0x521 , "DIU_REPLY_2");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x521ADD FAIL");
	}

	// HEX: 0x522 NAME: DIU_REPLY_3
	newHexID = new sDictonaryItem (0x522 , "DIU_REPLY_3");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x522ADD FAIL");
	}

	// HEX: 0x523 NAME: DIU_REPLY_4
	newHexID = new sDictonaryItem (0x523 , "DIU_REPLY_4");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x523ADD FAIL");
	}

	// HEX: 0x524 NAME: DIU_REPLY_5
	newHexID = new sDictonaryItem (0x524 , "DIU_REPLY_5");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x524ADD FAIL");
	}

	// HEX: 0x525 NAME: DIU_REPLY_6
	newHexID = new sDictonaryItem (0x525 , "DIU_REPLY_6");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x525ADD FAIL");
	}

	// HEX: 0x526 NAME: DIU_REPLY_7
	newHexID = new sDictonaryItem (0x526 , "DIU_REPLY_7");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x526ADD FAIL");
	}

	// HEX: 0x527 NAME: DIU_REPLY_8
	newHexID = new sDictonaryItem (0x527 , "DIU_REPLY_8");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x527ADD FAIL");
	}

	// HEX: 0x528 NAME: DIU_REPLY_9
	newHexID = new sDictonaryItem (0x528 , "DIU_REPLY_9");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x528ADD FAIL");
	}

	// HEX: 0x529 NAME: DIU_REPLY_10
	newHexID = new sDictonaryItem (0x529 , "DIU_REPLY_10");
	newHexID->addField("data_goes_here","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x529ADD FAIL");
	}

	// HEX: 0x600 NAME: BMU_Heartbeat
	newHexID = new sDictonaryItem (0x600 , "BMU_Heartbeat");
	newHexID->addField("Device_ID","bytes",4); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Serial_Number"," uintle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x600ADD FAIL");
	}

	// HEX: 0x601 NAME: CMU_1_Status
	newHexID = new sDictonaryItem (0x601 , "CMU_1_Status");
	newHexID->addField("Serial_Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x601ADD FAIL");
	}

	// HEX: 0x602 NAME: CMU_1_Cell0-3Voltage
	newHexID = new sDictonaryItem (0x602 , "CMU_1_Cell0-3Voltage");
	newHexID->addField("Cell_0_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_1_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_2_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_3_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x602ADD FAIL");
	}

	// HEX: 0x603 NAME: CMU_1_Cell4-7Voltage
	newHexID = new sDictonaryItem (0x603 , "CMU_1_Cell4-7Voltage");
	newHexID->addField("Cell_4_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_5_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_6_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_7_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x603ADD FAIL");
	}

	// HEX: 0x604 NAME: CMU_2_Status
	newHexID = new sDictonaryItem (0x604 , "CMU_2_Status");
	newHexID->addField("Serial_Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x604ADD FAIL");
	}

	// HEX: 0x605 NAME: CMU_2_Cell0-3Voltage
	newHexID = new sDictonaryItem (0x605 , "CMU_2_Cell0-3Voltage");
	newHexID->addField("Cell_0_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_1_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_2_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_3_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x605ADD FAIL");
	}

	// HEX: 0x606 NAME: CMU_2_Cell4-7Voltage
	newHexID = new sDictonaryItem (0x606 , "CMU_2_Cell4-7Voltage");
	newHexID->addField("Cell_4_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_5_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_6_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_7_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x606ADD FAIL");
	}

	// HEX: 0x607 NAME: CMU_3_Status
	newHexID = new sDictonaryItem (0x607 , "CMU_3_Status");
	newHexID->addField("Serial_Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x607ADD FAIL");
	}

	// HEX: 0x608 NAME: CMU_3_Cell0-3Voltage
	newHexID = new sDictonaryItem (0x608 , "CMU_3_Cell0-3Voltage");
	newHexID->addField("Cell_0_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_1_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_2_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_3_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x608ADD FAIL");
	}

	// HEX: 0x609 NAME: CMU_3_Cell4-7Voltage
	newHexID = new sDictonaryItem (0x609 , "CMU_3_Cell4-7Voltage");
	newHexID->addField("Cell_4_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_5_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_6_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_7_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x609ADD FAIL");
	}

	// HEX: 0x60a NAME: CMU_4_Status
	newHexID = new sDictonaryItem (0x60a , "CMU_4_Status");
	newHexID->addField("Serial_Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x60aADD FAIL");
	}

	// HEX: 0x60b NAME: CMU_4_Cell0-3Voltage
	newHexID = new sDictonaryItem (0x60b , "CMU_4_Cell0-3Voltage");
	newHexID->addField("Cell_0_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_1_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_2_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_3_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x60bADD FAIL");
	}

	// HEX: 0x60c NAME: CMU_4_Cell4-7Voltage
	newHexID = new sDictonaryItem (0x60c , "CMU_4_Cell4-7Voltage");
	newHexID->addField("Cell_4_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_5_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_6_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_7_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x60cADD FAIL");
	}

	// HEX: 0x60d NAME: CMU_5_Status
	newHexID = new sDictonaryItem (0x60d , "CMU_5_Status");
	newHexID->addField("Serial_Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x60dADD FAIL");
	}

	// HEX: 0x60e NAME: CMU_5_Cell0-3Voltage
	newHexID = new sDictonaryItem (0x60e , "CMU_5_Cell0-3Voltage");
	newHexID->addField("Cell_0_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_1_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_2_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_3_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x60eADD FAIL");
	}

	// HEX: 0x60f NAME: CMU_5_Cell4-7Voltage
	newHexID = new sDictonaryItem (0x60f , "CMU_5_Cell4-7Voltage");
	newHexID->addField("Cell_4_Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_5_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_6_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_7_Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x60fADD FAIL");
	}

	// HEX: 0x610 NAME: CMU 6 Status
	newHexID = new sDictonaryItem (0x610 , "CMU 6 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x610ADD FAIL");
	}

	// HEX: 0x611 NAME: CMU 6 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x611 , "CMU 6 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x611ADD FAIL");
	}

	// HEX: 0x612 NAME: CMU 6 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x612 , "CMU 6 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x612ADD FAIL");
	}

	// HEX: 0x613 NAME: CMU 7 Status
	newHexID = new sDictonaryItem (0x613 , "CMU 7 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x613ADD FAIL");
	}

	// HEX: 0x614 NAME: CMU 7 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x614 , "CMU 7 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x614ADD FAIL");
	}

	// HEX: 0x615 NAME: CMU 7 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x615 , "CMU 7 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x615ADD FAIL");
	}

	// HEX: 0x616 NAME: CMU 8 Status
	newHexID = new sDictonaryItem (0x616 , "CMU 8 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x616ADD FAIL");
	}

	// HEX: 0x617 NAME: CMU 8 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x617 , "CMU 8 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x617ADD FAIL");
	}

	// HEX: 0x618 NAME: CMU 8 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x618 , "CMU 8 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x618ADD FAIL");
	}

	// HEX: 0x619 NAME: CMU 9 Status
	newHexID = new sDictonaryItem (0x619 , "CMU 9 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x619ADD FAIL");
	}

	// HEX: 0x61a NAME: CMU 9 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x61a , "CMU 9 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x61aADD FAIL");
	}

	// HEX: 0x61b NAME: CMU 9 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x61b , "CMU 9 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x61bADD FAIL");
	}

	// HEX: 0x61c NAME: CMU 10 Status
	newHexID = new sDictonaryItem (0x61c , "CMU 10 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x61cADD FAIL");
	}

	// HEX: 0x61d NAME: CMU 10 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x61d , "CMU 10 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x61dADD FAIL");
	}

	// HEX: 0x61e NAME: CMU 10 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x61e , "CMU 10 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x61eADD FAIL");
	}

	// HEX: 0x61f NAME: CMU 11 Status
	newHexID = new sDictonaryItem (0x61f , "CMU 11 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x61fADD FAIL");
	}

	// HEX: 0x620 NAME: CMU 11 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x620 , "CMU 11 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x620ADD FAIL");
	}

	// HEX: 0x621 NAME: CMU 11 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x621 , "CMU 11 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x621ADD FAIL");
	}

	// HEX: 0x622 NAME: CMU 12 Status
	newHexID = new sDictonaryItem (0x622 , "CMU 12 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x622ADD FAIL");
	}

	// HEX: 0x623 NAME: CMU 12 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x623 , "CMU 12 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x623ADD FAIL");
	}

	// HEX: 0x624 NAME: CMU 12 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x624 , "CMU 12 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x624ADD FAIL");
	}

	// HEX: 0x625 NAME: CMU 13 Status
	newHexID = new sDictonaryItem (0x625 , "CMU 13 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x625ADD FAIL");
	}

	// HEX: 0x626 NAME: CMU 13 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x626 , "CMU 13 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x626ADD FAIL");
	}

	// HEX: 0x627 NAME: CMU 13 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x627 , "CMU 13 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x627ADD FAIL");
	}

	// HEX: 0x628 NAME: CMU 14 Status
	newHexID = new sDictonaryItem (0x628 , "CMU 14 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x628ADD FAIL");
	}

	// HEX: 0x629 NAME: CMU 14 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x629 , "CMU 14 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x629ADD FAIL");
	}

	// HEX: 0x62a NAME: CMU 14 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x62a , "CMU 14 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x62aADD FAIL");
	}

	// HEX: 0x62b NAME: CMU 15 Status
	newHexID = new sDictonaryItem (0x62b , "CMU 15 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x62bADD FAIL");
	}

	// HEX: 0x62c NAME: CMU 15 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x62c , "CMU 15 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x62cADD FAIL");
	}

	// HEX: 0x62d NAME: CMU 15 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x62d , "CMU 15 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x62dADD FAIL");
	}

	// HEX: 0x62e NAME: CMU 16 Status
	newHexID = new sDictonaryItem (0x62e , "CMU 16 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x62eADD FAIL");
	}

	// HEX: 0x62f NAME: CMU 16 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x62f , "CMU 16 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x62fADD FAIL");
	}

	// HEX: 0x630 NAME: CMU 16 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x630 , "CMU 16 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x630ADD FAIL");
	}

	// HEX: 0x631 NAME: CMU 17 Status
	newHexID = new sDictonaryItem (0x631 , "CMU 17 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x631ADD FAIL");
	}

	// HEX: 0x632 NAME: CMU 17 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x632 , "CMU 17 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x632ADD FAIL");
	}

	// HEX: 0x633 NAME: CMU 17 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x633 , "CMU 17 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x633ADD FAIL");
	}

	// HEX: 0x634 NAME: CMU 18 Status
	newHexID = new sDictonaryItem (0x634 , "CMU 18 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x634ADD FAIL");
	}

	// HEX: 0x635 NAME: CMU 18 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x635 , "CMU 18 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x635ADD FAIL");
	}

	// HEX: 0x636 NAME: CMU 18 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x636 , "CMU 18 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x636ADD FAIL");
	}

	// HEX: 0x637 NAME: CMU 19 Status
	newHexID = new sDictonaryItem (0x637 , "CMU 19 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x637ADD FAIL");
	}

	// HEX: 0x638 NAME: CMU 19 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x638 , "CMU 19 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x638ADD FAIL");
	}

	// HEX: 0x639 NAME: CMU 19 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x639 , "CMU 19 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x639ADD FAIL");
	}

	// HEX: 0x63a NAME: CMU 20 Status
	newHexID = new sDictonaryItem (0x63a , "CMU 20 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x63aADD FAIL");
	}

	// HEX: 0x63b NAME: CMU 20 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x63b , "CMU 20 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x63bADD FAIL");
	}

	// HEX: 0x63c NAME: CMU 20 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x63c , "CMU 20 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x63cADD FAIL");
	}

	// HEX: 0x63d NAME: CMU 21 Status
	newHexID = new sDictonaryItem (0x63d , "CMU 21 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x63dADD FAIL");
	}

	// HEX: 0x63e NAME: CMU 21 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x63e , "CMU 21 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x63eADD FAIL");
	}

	// HEX: 0x63f NAME: CMU 21 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x63f , "CMU 21 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x63fADD FAIL");
	}

	// HEX: 0x640 NAME: CMU 22 Status
	newHexID = new sDictonaryItem (0x640 , "CMU 22 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x640ADD FAIL");
	}

	// HEX: 0x641 NAME: CMU 22 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x641 , "CMU 22 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x641ADD FAIL");
	}

	// HEX: 0x642 NAME: CMU 22 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x642 , "CMU 22 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x642ADD FAIL");
	}

	// HEX: 0x643 NAME: CMU 23 Status
	newHexID = new sDictonaryItem (0x643 , "CMU 23 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x643ADD FAIL");
	}

	// HEX: 0x644 NAME: CMU 23 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x644 , "CMU 23 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x644ADD FAIL");
	}

	// HEX: 0x645 NAME: CMU 23 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x645 , "CMU 23 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x645ADD FAIL");
	}

	// HEX: 0x646 NAME: CMU 24 Status
	newHexID = new sDictonaryItem (0x646 , "CMU 24 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x646ADD FAIL");
	}

	// HEX: 0x647 NAME: CMU 24 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x647 , "CMU 24 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x647ADD FAIL");
	}

	// HEX: 0x648 NAME: CMU 24 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x648 , "CMU 24 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x648ADD FAIL");
	}

	// HEX: 0x649 NAME: CMU 25 Status
	newHexID = new sDictonaryItem (0x649 , "CMU 25 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x649ADD FAIL");
	}

	// HEX: 0x64a NAME: CMU 25 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x64a , "CMU 25 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x64aADD FAIL");
	}

	// HEX: 0x64b NAME: CMU 25 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x64b , "CMU 25 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x64bADD FAIL");
	}

	// HEX: 0x64c NAME: CMU 26 Status
	newHexID = new sDictonaryItem (0x64c , "CMU 26 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x64cADD FAIL");
	}

	// HEX: 0x64d NAME: CMU 26 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x64d , "CMU 26 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x64dADD FAIL");
	}

	// HEX: 0x64e NAME: CMU 26 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x64e , "CMU 26 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x64eADD FAIL");
	}

	// HEX: 0x64f NAME: CMU 27 Status
	newHexID = new sDictonaryItem (0x64f , "CMU 27 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x64fADD FAIL");
	}

	// HEX: 0x650 NAME: CMU 27 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x650 , "CMU 27 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x650ADD FAIL");
	}

	// HEX: 0x651 NAME: CMU 27 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x651 , "CMU 27 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x651ADD FAIL");
	}

	// HEX: 0x652 NAME: CMU 28 Status
	newHexID = new sDictonaryItem (0x652 , "CMU 28 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x652ADD FAIL");
	}

	// HEX: 0x653 NAME: CMU 28 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x653 , "CMU 28 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x653ADD FAIL");
	}

	// HEX: 0x654 NAME: CMU 28 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x654 , "CMU 28 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x654ADD FAIL");
	}

	// HEX: 0x655 NAME: CMU 29 Status
	newHexID = new sDictonaryItem (0x655 , "CMU 29 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x655ADD FAIL");
	}

	// HEX: 0x656 NAME: CMU 29 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x656 , "CMU 29 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x656ADD FAIL");
	}

	// HEX: 0x657 NAME: CMU 29 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x657 , "CMU 29 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x657ADD FAIL");
	}

	// HEX: 0x658 NAME: CMU 30 Status
	newHexID = new sDictonaryItem (0x658 , "CMU 30 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x658ADD FAIL");
	}

	// HEX: 0x659 NAME: CMU 30 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x659 , "CMU 30 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x659ADD FAIL");
	}

	// HEX: 0x65a NAME: CMU 30 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x65a , "CMU 30 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x65aADD FAIL");
	}

	// HEX: 0x65b NAME: CMU 31 Status
	newHexID = new sDictonaryItem (0x65b , "CMU 31 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x65bADD FAIL");
	}

	// HEX: 0x65c NAME: CMU 31 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x65c , "CMU 31 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x65cADD FAIL");
	}

	// HEX: 0x65d NAME: CMU 31 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x65d , "CMU 31 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x65dADD FAIL");
	}

	// HEX: 0x65e NAME: CMU 32 Status
	newHexID = new sDictonaryItem (0x65e , "CMU 32 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x65eADD FAIL");
	}

	// HEX: 0x65f NAME: CMU 32 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x65f , "CMU 32 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x65fADD FAIL");
	}

	// HEX: 0x660 NAME: CMU 32 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x660 , "CMU 32 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x660ADD FAIL");
	}

	// HEX: 0x661 NAME: CMU 33 Status
	newHexID = new sDictonaryItem (0x661 , "CMU 33 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x661ADD FAIL");
	}

	// HEX: 0x662 NAME: CMU 33 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x662 , "CMU 33 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x662ADD FAIL");
	}

	// HEX: 0x663 NAME: CMU 33 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x663 , "CMU 33 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x663ADD FAIL");
	}

	// HEX: 0x664 NAME: CMU 34 Status
	newHexID = new sDictonaryItem (0x664 , "CMU 34 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x664ADD FAIL");
	}

	// HEX: 0x665 NAME: CMU 34 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x665 , "CMU 34 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x665ADD FAIL");
	}

	// HEX: 0x666 NAME: CMU 34 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x666 , "CMU 34 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x666ADD FAIL");
	}

	// HEX: 0x667 NAME: CMU 35 Status
	newHexID = new sDictonaryItem (0x667 , "CMU 35 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x667ADD FAIL");
	}

	// HEX: 0x668 NAME: CMU 35 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x668 , "CMU 35 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x668ADD FAIL");
	}

	// HEX: 0x669 NAME: CMU 35 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x669 , "CMU 35 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x669ADD FAIL");
	}

	// HEX: 0x66a NAME: CMU 36 Status
	newHexID = new sDictonaryItem (0x66a , "CMU 36 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x66aADD FAIL");
	}

	// HEX: 0x66b NAME: CMU 36 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x66b , "CMU 36 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x66bADD FAIL");
	}

	// HEX: 0x66c NAME: CMU 36 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x66c , "CMU 36 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x66cADD FAIL");
	}

	// HEX: 0x66d NAME: CMU 37 Status
	newHexID = new sDictonaryItem (0x66d , "CMU 37 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x66dADD FAIL");
	}

	// HEX: 0x66e NAME: CMU 37 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x66e , "CMU 37 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x66eADD FAIL");
	}

	// HEX: 0x66f NAME: CMU 37 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x66f , "CMU 37 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x66fADD FAIL");
	}

	// HEX: 0x670 NAME: CMU 38 Status
	newHexID = new sDictonaryItem (0x670 , "CMU 38 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x670ADD FAIL");
	}

	// HEX: 0x671 NAME: CMU 38 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x671 , "CMU 38 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x671ADD FAIL");
	}

	// HEX: 0x672 NAME: CMU 38 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x672 , "CMU 38 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x672ADD FAIL");
	}

	// HEX: 0x673 NAME: CMU 39 Status
	newHexID = new sDictonaryItem (0x673 , "CMU 39 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x673ADD FAIL");
	}

	// HEX: 0x674 NAME: CMU 39 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x674 , "CMU 39 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x674ADD FAIL");
	}

	// HEX: 0x675 NAME: CMU 39 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x675 , "CMU 39 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x675ADD FAIL");
	}

	// HEX: 0x676 NAME: CMU 40 Status
	newHexID = new sDictonaryItem (0x676 , "CMU 40 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x676ADD FAIL");
	}

	// HEX: 0x677 NAME: CMU 40 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x677 , "CMU 40 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x677ADD FAIL");
	}

	// HEX: 0x678 NAME: CMU 40 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x678 , "CMU 40 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x678ADD FAIL");
	}

	// HEX: 0x679 NAME: CMU 41 Status
	newHexID = new sDictonaryItem (0x679 , "CMU 41 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x679ADD FAIL");
	}

	// HEX: 0x67a NAME: CMU 41 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x67a , "CMU 41 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x67aADD FAIL");
	}

	// HEX: 0x67b NAME: CMU 41 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x67b , "CMU 41 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x67bADD FAIL");
	}

	// HEX: 0x67c NAME: CMU 42 Status
	newHexID = new sDictonaryItem (0x67c , "CMU 42 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x67cADD FAIL");
	}

	// HEX: 0x67d NAME: CMU 42 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x67d , "CMU 42 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x67dADD FAIL");
	}

	// HEX: 0x67e NAME: CMU 42 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x67e , "CMU 42 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x67eADD FAIL");
	}

	// HEX: 0x67f NAME: CMU 43 Status
	newHexID = new sDictonaryItem (0x67f , "CMU 43 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x67fADD FAIL");
	}

	// HEX: 0x680 NAME: CMU 43 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x680 , "CMU 43 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x680ADD FAIL");
	}

	// HEX: 0x681 NAME: CMU 43 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x681 , "CMU 43 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x681ADD FAIL");
	}

	// HEX: 0x682 NAME: CMU 44 Status
	newHexID = new sDictonaryItem (0x682 , "CMU 44 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x682ADD FAIL");
	}

	// HEX: 0x683 NAME: CMU 44 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x683 , "CMU 44 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x683ADD FAIL");
	}

	// HEX: 0x684 NAME: CMU 44 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x684 , "CMU 44 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x684ADD FAIL");
	}

	// HEX: 0x685 NAME: CMU 45 Status
	newHexID = new sDictonaryItem (0x685 , "CMU 45 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x685ADD FAIL");
	}

	// HEX: 0x686 NAME: CMU 45 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x686 , "CMU 45 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x686ADD FAIL");
	}

	// HEX: 0x687 NAME: CMU 45 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x687 , "CMU 45 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x687ADD FAIL");
	}

	// HEX: 0x688 NAME: CMU 46 Status
	newHexID = new sDictonaryItem (0x688 , "CMU 46 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x688ADD FAIL");
	}

	// HEX: 0x689 NAME: CMU 46 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x689 , "CMU 46 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x689ADD FAIL");
	}

	// HEX: 0x68a NAME: CMU 46 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x68a , "CMU 46 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x68aADD FAIL");
	}

	// HEX: 0x68b NAME: CMU 47 Status
	newHexID = new sDictonaryItem (0x68b , "CMU 47 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x68bADD FAIL");
	}

	// HEX: 0x68c NAME: CMU 47 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x68c , "CMU 47 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x68cADD FAIL");
	}

	// HEX: 0x68d NAME: CMU 47 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x68d , "CMU 47 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x68dADD FAIL");
	}

	// HEX: 0x68e NAME: CMU 48 Status
	newHexID = new sDictonaryItem (0x68e , "CMU 48 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x68eADD FAIL");
	}

	// HEX: 0x68f NAME: CMU 48 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x68f , "CMU 48 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x68fADD FAIL");
	}

	// HEX: 0x690 NAME: CMU 48 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x690 , "CMU 48 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x690ADD FAIL");
	}

	// HEX: 0x691 NAME: CMU 49 Status
	newHexID = new sDictonaryItem (0x691 , "CMU 49 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x691ADD FAIL");
	}

	// HEX: 0x692 NAME: CMU 49 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x692 , "CMU 49 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x692ADD FAIL");
	}

	// HEX: 0x693 NAME: CMU 49 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x693 , "CMU 49 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x693ADD FAIL");
	}

	// HEX: 0x694 NAME: CMU 50 Status
	newHexID = new sDictonaryItem (0x694 , "CMU 50 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x694ADD FAIL");
	}

	// HEX: 0x695 NAME: CMU 50 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x695 , "CMU 50 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x695ADD FAIL");
	}

	// HEX: 0x696 NAME: CMU 50 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x696 , "CMU 50 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x696ADD FAIL");
	}

	// HEX: 0x697 NAME: CMU 51 Status
	newHexID = new sDictonaryItem (0x697 , "CMU 51 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x697ADD FAIL");
	}

	// HEX: 0x698 NAME: CMU 51 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x698 , "CMU 51 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x698ADD FAIL");
	}

	// HEX: 0x699 NAME: CMU 51 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x699 , "CMU 51 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x699ADD FAIL");
	}

	// HEX: 0x69a NAME: CMU 52 Status
	newHexID = new sDictonaryItem (0x69a , "CMU 52 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x69aADD FAIL");
	}

	// HEX: 0x69b NAME: CMU 52 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x69b , "CMU 52 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x69bADD FAIL");
	}

	// HEX: 0x69c NAME: CMU 52 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x69c , "CMU 52 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x69cADD FAIL");
	}

	// HEX: 0x69d NAME: CMU 53 Status
	newHexID = new sDictonaryItem (0x69d , "CMU 53 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x69dADD FAIL");
	}

	// HEX: 0x69e NAME: CMU 53 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x69e , "CMU 53 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x69eADD FAIL");
	}

	// HEX: 0x69f NAME: CMU 53 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x69f , "CMU 53 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x69fADD FAIL");
	}

	// HEX: 0x6a0 NAME: CMU 54 Status
	newHexID = new sDictonaryItem (0x6a0 , "CMU 54 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a0ADD FAIL");
	}

	// HEX: 0x6a1 NAME: CMU 54 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6a1 , "CMU 54 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a1ADD FAIL");
	}

	// HEX: 0x6a2 NAME: CMU 54 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6a2 , "CMU 54 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a2ADD FAIL");
	}

	// HEX: 0x6a3 NAME: CMU 55 Status
	newHexID = new sDictonaryItem (0x6a3 , "CMU 55 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a3ADD FAIL");
	}

	// HEX: 0x6a4 NAME: CMU 55 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6a4 , "CMU 55 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a4ADD FAIL");
	}

	// HEX: 0x6a5 NAME: CMU 55 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6a5 , "CMU 55 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a5ADD FAIL");
	}

	// HEX: 0x6a6 NAME: CMU 56 Status
	newHexID = new sDictonaryItem (0x6a6 , "CMU 56 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a6ADD FAIL");
	}

	// HEX: 0x6a7 NAME: CMU 56 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6a7 , "CMU 56 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a7ADD FAIL");
	}

	// HEX: 0x6a8 NAME: CMU 56 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6a8 , "CMU 56 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a8ADD FAIL");
	}

	// HEX: 0x6a9 NAME: CMU 57 Status
	newHexID = new sDictonaryItem (0x6a9 , "CMU 57 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6a9ADD FAIL");
	}

	// HEX: 0x6aa NAME: CMU 57 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6aa , "CMU 57 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6aaADD FAIL");
	}

	// HEX: 0x6ab NAME: CMU 57 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6ab , "CMU 57 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6abADD FAIL");
	}

	// HEX: 0x6ac NAME: CMU 58 Status
	newHexID = new sDictonaryItem (0x6ac , "CMU 58 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6acADD FAIL");
	}

	// HEX: 0x6ad NAME: CMU 58 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6ad , "CMU 58 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6adADD FAIL");
	}

	// HEX: 0x6ae NAME: CMU 58 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6ae , "CMU 58 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6aeADD FAIL");
	}

	// HEX: 0x6af NAME: CMU 59 Status
	newHexID = new sDictonaryItem (0x6af , "CMU 59 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6afADD FAIL");
	}

	// HEX: 0x6b0 NAME: CMU 59 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6b0 , "CMU 59 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b0ADD FAIL");
	}

	// HEX: 0x6b1 NAME: CMU 59 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6b1 , "CMU 59 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b1ADD FAIL");
	}

	// HEX: 0x6b2 NAME: CMU 60 Status
	newHexID = new sDictonaryItem (0x6b2 , "CMU 60 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b2ADD FAIL");
	}

	// HEX: 0x6b3 NAME: CMU 60 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6b3 , "CMU 60 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b3ADD FAIL");
	}

	// HEX: 0x6b4 NAME: CMU 60 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6b4 , "CMU 60 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b4ADD FAIL");
	}

	// HEX: 0x6b5 NAME: CMU 61 Status
	newHexID = new sDictonaryItem (0x6b5 , "CMU 61 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b5ADD FAIL");
	}

	// HEX: 0x6b6 NAME: CMU 61 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6b6 , "CMU 61 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b6ADD FAIL");
	}

	// HEX: 0x6b7 NAME: CMU 61 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6b7 , "CMU 61 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b7ADD FAIL");
	}

	// HEX: 0x6b8 NAME: CMU 62 Status
	newHexID = new sDictonaryItem (0x6b8 , "CMU 62 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b8ADD FAIL");
	}

	// HEX: 0x6b9 NAME: CMU 62 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6b9 , "CMU 62 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6b9ADD FAIL");
	}

	// HEX: 0x6ba NAME: CMU 62 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6ba , "CMU 62 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6baADD FAIL");
	}

	// HEX: 0x6bb NAME: CMU 63 Status
	newHexID = new sDictonaryItem (0x6bb , "CMU 63 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6bbADD FAIL");
	}

	// HEX: 0x6bc NAME: CMU 63 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6bc , "CMU 63 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6bcADD FAIL");
	}

	// HEX: 0x6bd NAME: CMU 63 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6bd , "CMU 63 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6bdADD FAIL");
	}

	// HEX: 0x6be NAME: CMU 64 Status
	newHexID = new sDictonaryItem (0x6be , "CMU 64 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6beADD FAIL");
	}

	// HEX: 0x6bf NAME: CMU 64 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6bf , "CMU 64 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6bfADD FAIL");
	}

	// HEX: 0x6c0 NAME: CMU 64 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6c0 , "CMU 64 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c0ADD FAIL");
	}

	// HEX: 0x6c1 NAME: CMU 65 Status
	newHexID = new sDictonaryItem (0x6c1 , "CMU 65 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c1ADD FAIL");
	}

	// HEX: 0x6c2 NAME: CMU 65 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6c2 , "CMU 65 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c2ADD FAIL");
	}

	// HEX: 0x6c3 NAME: CMU 65 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6c3 , "CMU 65 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c3ADD FAIL");
	}

	// HEX: 0x6c4 NAME: CMU 66 Status
	newHexID = new sDictonaryItem (0x6c4 , "CMU 66 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c4ADD FAIL");
	}

	// HEX: 0x6c5 NAME: CMU 66 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6c5 , "CMU 66 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c5ADD FAIL");
	}

	// HEX: 0x6c6 NAME: CMU 66 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6c6 , "CMU 66 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c6ADD FAIL");
	}

	// HEX: 0x6c7 NAME: CMU 67 Status
	newHexID = new sDictonaryItem (0x6c7 , "CMU 67 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c7ADD FAIL");
	}

	// HEX: 0x6c8 NAME: CMU 67 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6c8 , "CMU 67 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c8ADD FAIL");
	}

	// HEX: 0x6c9 NAME: CMU 67 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6c9 , "CMU 67 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6c9ADD FAIL");
	}

	// HEX: 0x6ca NAME: CMU 68 Status
	newHexID = new sDictonaryItem (0x6ca , "CMU 68 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6caADD FAIL");
	}

	// HEX: 0x6cb NAME: CMU 68 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6cb , "CMU 68 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6cbADD FAIL");
	}

	// HEX: 0x6cc NAME: CMU 68 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6cc , "CMU 68 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6ccADD FAIL");
	}

	// HEX: 0x6cd NAME: CMU 69 Status
	newHexID = new sDictonaryItem (0x6cd , "CMU 69 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6cdADD FAIL");
	}

	// HEX: 0x6ce NAME: CMU 69 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6ce , "CMU 69 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6ceADD FAIL");
	}

	// HEX: 0x6cf NAME: CMU 69 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6cf , "CMU 69 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6cfADD FAIL");
	}

	// HEX: 0x6d0 NAME: CMU 70 Status
	newHexID = new sDictonaryItem (0x6d0 , "CMU 70 Status");
	newHexID->addField("cmu_serial_number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("pcb_temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("cell_temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d0ADD FAIL");
	}

	// HEX: 0x6d1 NAME: CMU 70 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6d1 , "CMU 70 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d1ADD FAIL");
	}

	// HEX: 0x6d2 NAME: CMU 70 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6d2 , "CMU 70 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d2ADD FAIL");
	}

	// HEX: 0x6d3 NAME: CMU 71 Status
	newHexID = new sDictonaryItem (0x6d3 , "CMU 71 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d3ADD FAIL");
	}

	// HEX: 0x6d4 NAME: CMU 71 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6d4 , "CMU 71 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d4ADD FAIL");
	}

	// HEX: 0x6d5 NAME: CMU 71 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6d5 , "CMU 71 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d5ADD FAIL");
	}

	// HEX: 0x6d6 NAME: CMU 72 Status
	newHexID = new sDictonaryItem (0x6d6 , "CMU 72 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d6ADD FAIL");
	}

	// HEX: 0x6d7 NAME: CMU 72 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6d7 , "CMU 72 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d7ADD FAIL");
	}

	// HEX: 0x6d8 NAME: CMU 72 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6d8 , "CMU 72 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d8ADD FAIL");
	}

	// HEX: 0x6d9 NAME: CMU 73 Status
	newHexID = new sDictonaryItem (0x6d9 , "CMU 73 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6d9ADD FAIL");
	}

	// HEX: 0x6da NAME: CMU 73 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6da , "CMU 73 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6daADD FAIL");
	}

	// HEX: 0x6db NAME: CMU 73 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6db , "CMU 73 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6dbADD FAIL");
	}

	// HEX: 0x6dc NAME: CMU 74 Status
	newHexID = new sDictonaryItem (0x6dc , "CMU 74 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6dcADD FAIL");
	}

	// HEX: 0x6dd NAME: CMU 74 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6dd , "CMU 74 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6ddADD FAIL");
	}

	// HEX: 0x6de NAME: CMU 74 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6de , "CMU 74 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6deADD FAIL");
	}

	// HEX: 0x6df NAME: CMU 75 Status
	newHexID = new sDictonaryItem (0x6df , "CMU 75 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6dfADD FAIL");
	}

	// HEX: 0x6e0 NAME: CMU 75 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6e0 , "CMU 75 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e0ADD FAIL");
	}

	// HEX: 0x6e1 NAME: CMU 75 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6e1 , "CMU 75 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e1ADD FAIL");
	}

	// HEX: 0x6e2 NAME: CMU 76 Status
	newHexID = new sDictonaryItem (0x6e2 , "CMU 76 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e2ADD FAIL");
	}

	// HEX: 0x6e3 NAME: CMU 76 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6e3 , "CMU 76 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e3ADD FAIL");
	}

	// HEX: 0x6e4 NAME: CMU 76 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6e4 , "CMU 76 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e4ADD FAIL");
	}

	// HEX: 0x6e5 NAME: CMU 77 Status
	newHexID = new sDictonaryItem (0x6e5 , "CMU 77 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e5ADD FAIL");
	}

	// HEX: 0x6e6 NAME: CMU 77 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6e6 , "CMU 77 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e6ADD FAIL");
	}

	// HEX: 0x6e7 NAME: CMU 77 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6e7 , "CMU 77 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e7ADD FAIL");
	}

	// HEX: 0x6e8 NAME: CMU 78 Status
	newHexID = new sDictonaryItem (0x6e8 , "CMU 78 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e8ADD FAIL");
	}

	// HEX: 0x6e9 NAME: CMU 78 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6e9 , "CMU 78 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6e9ADD FAIL");
	}

	// HEX: 0x6ea NAME: CMU 78 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6ea , "CMU 78 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6eaADD FAIL");
	}

	// HEX: 0x6eb NAME: CMU 79 Status
	newHexID = new sDictonaryItem (0x6eb , "CMU 79 Status");
	newHexID->addField("Serial Number","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("PCB Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6ebADD FAIL");
	}

	// HEX: 0x6ec NAME: CMU 79 Cell0-3Voltage
	newHexID = new sDictonaryItem (0x6ec , "CMU 79 Cell0-3Voltage");
	newHexID->addField("Cell 0 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 1 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 2 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 3 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6ecADD FAIL");
	}

	// HEX: 0x6ed NAME: CMU 79 Cell4-7Voltage
	newHexID = new sDictonaryItem (0x6ed , "CMU 79 Cell4-7Voltage");
	newHexID->addField("Cell 4 Voltage","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 5 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 6 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell 7 Voltage"," intle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6edADD FAIL");
	}

	// HEX: 0x6ee NAME: BMU_UNKNOWN
	newHexID = new sDictonaryItem (0x6ee , "BMU_UNKNOWN");
	newHexID->addField("unknown","bin",64); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6eeADD FAIL");
	}

	// HEX: 0x6ef NAME: BMU_UNKNOWN
	newHexID = new sDictonaryItem (0x6ef , "BMU_UNKNOWN");
	newHexID->addField("unknown","bin",64); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6efADD FAIL");
	}

	// HEX: 0x6f0 NAME: BMU_FACTORY_CONFIG_AND_CALIBRATION
	newHexID = new sDictonaryItem (0x6f0 , "BMU_FACTORY_CONFIG_AND_CALIBRATION");
	newHexID->addField("reserved","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f0ADD FAIL");
	}

	// HEX: 0x6f1 NAME: BMU_RESERVED_1
	newHexID = new sDictonaryItem (0x6f1 , "BMU_RESERVED_1");
	newHexID->addField("reserved","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f1ADD FAIL");
	}

	// HEX: 0x6f2 NAME: BMU_RESERVED_2
	newHexID = new sDictonaryItem (0x6f2 , "BMU_RESERVED_2");
	newHexID->addField("reserved","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f2ADD FAIL");
	}

	// HEX: 0x6f3 NAME: BMU_RESERVED_3
	newHexID = new sDictonaryItem (0x6f3 , "BMU_RESERVED_3");
	newHexID->addField("reserved","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f3ADD FAIL");
	}

	// HEX: 0x6f4 NAME: Pack_State_of_Charge
	newHexID = new sDictonaryItem (0x6f4 , "Pack_State_of_Charge");
	newHexID->addField("SOCA","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("SOCP"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f4ADD FAIL");
	}

	// HEX: 0x6f5 NAME: Pack_Balance_State_of_Charge
	newHexID = new sDictonaryItem (0x6f5 , "Pack_Balance_State_of_Charge");
	newHexID->addField("Balance_SOCA","floatle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Balance_SOCP"," floatle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f5ADD FAIL");
	}

	// HEX: 0x6f6 NAME: Charger_Control_Information
	newHexID = new sDictonaryItem (0x6f6 , "Charger_Control_Information");
	newHexID->addField("Charging_Cell_Voltage_Error","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_Temperature_Margin"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Discharging_Cell_Voltage_Error"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Total_Pack_Capacity"," uintle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f6ADD FAIL");
	}

	// HEX: 0x6f7 NAME: Precharge_Status
	newHexID = new sDictonaryItem (0x6f7 , "Precharge_Status");
	newHexID->addField("Error_Status_of_Contactor_1","bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Error_Status_of_Contactor_2"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Output_Status_of_Contactor_1"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Output_Status_of_Contactor_2"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("12V_Contactor_Supply_Voltage_Status"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Error_Status_of_Contactor_3_Driver"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Output_Status_of_Contactor_3_Driver"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("unused"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Precharge_State"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("12V_Contactor_Supply_Voltage"," uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("unused"," uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Precharge_Timer_Elapsed"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Precharge_Timer_Counter"," uintle",8); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f7ADD FAIL");
	}

	// HEX: 0x6f8 NAME: Minimum_/_Maximum_Cell_Voltage
	newHexID = new sDictonaryItem (0x6f8 , "Minimum_/_Maximum_Cell_Voltage");
	newHexID->addField("Minimum_Cell_Voltage","uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Maximum_Cell_Voltage"," uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("CMU_with_Minimum_Voltage"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_with_Minimum_Voltage"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("CMU_with_Maximum_Voltage"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Cell_with_Maximum_Voltage"," uintle",8); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f8ADD FAIL");
	}

	// HEX: 0x6f9 NAME: Minimum_/_Maximum_Cell_Temperature
	newHexID = new sDictonaryItem (0x6f9 , "Minimum_/_Maximum_Cell_Temperature");
	newHexID->addField("Minimum_Cell_Temperature","intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Maximum_Cell_Temperature"," intle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("CMU_with_Minimum_Cell_Temperature"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("unused"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("CMU_with_Maximum_Cell_Temperature"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("unused"," uintle",8); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6f9ADD FAIL");
	}

	// HEX: 0x6fa NAME: Battery_Pack_Voltage_/_Current
	newHexID = new sDictonaryItem (0x6fa , "Battery_Pack_Voltage_/_Current");
	newHexID->addField("Battery_Voltage","uintle",32); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Battery_Current"," intle",32); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6faADD FAIL");
	}

	// HEX: 0x6fb NAME: Battery_Pack_Status
	newHexID = new sDictonaryItem (0x6fb , "Battery_Pack_Status");
	newHexID->addField("Balance_Voltage_Threshold_-_Rising","uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Balance_Voltage_Threshold_-_Falling"," uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("CMU_CAN_Bus_Power_Status"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("BMU_is_in_Setup_Mode"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Vehicle_Communications_Timeout"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("CMU_Communications_Timeout"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Measurement_Untrusted"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Cell_Over_Temperature"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Cell_Under_Voltage"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Cell_Over_Voltage"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("BMS_CMU Count"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("BMS_Firmware_Build_Number"," uintle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6fbADD FAIL");
	}

	// HEX: 0x6fc NAME: Battery_Pack_Fan_Status
	newHexID = new sDictonaryItem (0x6fc , "Battery_Pack_Fan_Status");
	newHexID->addField("Fan_Speed_0","uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Fan_Speed_1"," uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("12V_Current_Consumption_of_Fans_and_Contactors"," uintle",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("12V_Current_Consumption_of_CMUs"," uintle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6fcADD FAIL");
	}

	// HEX: 0x6fd NAME: Extended_Battery_Pack_Status
	newHexID = new sDictonaryItem (0x6fd , "Extended_Battery_Pack_Status");
	newHexID->addField("CMU_CAN_Bus_Power_Status","bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("BMU_is_in_Setup_Mode"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Vehicle_Communications_Timeout"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("CMU_Communications_Timeout"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Measurement_Untrusted"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Cell_Over_Temperature"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Cell_Under_Voltage"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Cell_Over_Voltage"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("sf_unused_3"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("sf_unused_2"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("sf_unused_1"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("CMU_has_detected_an_extra_Cell"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Contactor_is_Stuck_/_Not_Engaged"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("CAN_12V_Too_Low"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("SOC_Measurement_is_not_Valid"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Pack_Isolation_Test_Failure"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("unused"," bin",16); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("BMU_Hardware_Version"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("BMU_Model_ID"," uintle",8); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("unused"," uintle",16); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6fdADD FAIL");
	}

	// HEX: 0x6fe NAME: BMU_RESERVED_UNUSED_1
	newHexID = new sDictonaryItem (0x6fe , "BMU_RESERVED_UNUSED_1");
	newHexID->addField("unknown","hex",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6feADD FAIL");
	}

	// HEX: 0x6ff NAME: BMU_RESERVED_UNUSED_2
	newHexID = new sDictonaryItem (0x6ff , "BMU_RESERVED_UNUSED_2");
	newHexID->addField("unknown","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x6ffADD FAIL");
	}

	// HEX: 0x701 NAME: MPPT1
	newHexID = new sDictonaryItem (0x701 , "MPPT1");
	newHexID->addField("Battery Over Voltage","bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Over Temperature"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("No Connection"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Under Voltage"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Uin"," pad",2); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Iin"," int",10); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Uout"," pad",6); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Temperature"," int",10); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x701ADD FAIL");
	}

	// HEX: 0x702 NAME: MPPT2
	newHexID = new sDictonaryItem (0x702 , "MPPT2");
	newHexID->addField("Battery Over Voltage","bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Over Temperature"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("No Connection"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Under Voltage"," bool",0); // Field is VARIABLE or non-existant
	newHexID->addField("Uin"," pad",2); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Iin"," int",10); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Uout"," pad",6); // NAME:TYPE:SIZE(BITS)
	newHexID->addField("Temperature"," int",10); // NAME:TYPE:SIZE(BITS)
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x702ADD FAIL");
	}

	// HEX: 0x731 NAME: MPPT_MASTER_REQUEST_FRAME
	newHexID = new sDictonaryItem (0x731 , "MPPT_MASTER_REQUEST_FRAME");
	newHexID->addField("empty_data_field","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x731ADD FAIL");
	}

	// HEX: 0x732 NAME: MPPT_MASTER_REQUEST_FRAME
	newHexID = new sDictonaryItem (0x732 , "MPPT_MASTER_REQUEST_FRAME");
	newHexID->addField("empty_data_field","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x732ADD FAIL");
	}

	// HEX: 0x7f0 NAME: BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_1
	newHexID = new sDictonaryItem (0x7f0 , "BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_1");
	newHexID->addField("unknown","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x7f0ADD FAIL");
	}

	// HEX: 0x7f1 NAME: BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_2
	newHexID = new sDictonaryItem (0x7f1 , "BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_2");
	newHexID->addField("unknown","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x7f1ADD FAIL");
	}

	// HEX: 0x7f2 NAME: BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_3
	newHexID = new sDictonaryItem (0x7f2 , "BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_3");
	newHexID->addField("unknown","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x7f2ADD FAIL");
	}

	// HEX: 0x7f3 NAME: BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_4
	newHexID = new sDictonaryItem (0x7f3 , "BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_4");
	newHexID->addField("unknown","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x7f3ADD FAIL");
	}

	// HEX: 0x7f4 NAME: BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_5
	newHexID = new sDictonaryItem (0x7f4 , "BMU_RESERVED_FOR_BOOTLOADER_TRIGGERING_AND_DATA_TRANSFER_5");
	newHexID->addField("unknown","bin",0); // Field is VARIABLE or non-existant
	if (!addDictonaryRecord ( newHexID )){
		printf("[EXPORT.CPP] HEX REC 0x7f4ADD FAIL");
	}

}
