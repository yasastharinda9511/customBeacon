
#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <tins/tins.h>

#define EMERGENCY_VEHICLE_MESSAGE 0x41
#define LANE_CHANGING_MESSAGE 0x42
#define BASIC_SAFETY_MESSAGE 0x43
#define SUDDEN_BRAKE_MESSAGE 0x44

// PRIORITY LEVELS//

#define PRIORITY_1 0x45
#define PRIORITY_2 0x46
#define PRIORITY_3 0x47
#define PRIORITY_4 0x48
#define PRIORITY_NONE 0x49

/*

Present flags parameters
Present Flag - |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
                  1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    
* 1-type
* 2-id
* 3-speed
* 4-accel
* 5-position
* 6-direction
* 7-lane
* 8-status

*/
#define VEHICLE_TYPE_FLAG   0x0001 << 15
#define VEHICLE_ID_FLAG     0x0001 << 14
#define VEHICLE_SPEED_FLAG  0x0001 << 13
#define VEHICLE_ACCEL_FLAG  0x0001 << 12
#define VEHICLE_POS_FLAG    0x0001 << 11
#define VEHICLE_DIR_FLAG    0x0001 << 10
#define VEHICLE_LANE_FLAG   0x0001 << 9
#define VEHICLE_STATUS_FLAG 0x0001 << 8

// Data PRIORITIES//

#define VEHICLE_TYPE_CAR 0x41
#define VEHICLE_TYPE_VAN 0x42
#define VEHICLE_TYPE_BUS 0x43
#define VEHICLE_TYPE_AMBULANCE 0x44


// Data Types
typedef struct data{

	uint8_t priority;
        uint8_t msgCategory;
        uint32_t count;

	uint8_t type;
        uint8_t vehicle_id[4];
        uint16_t present = 0x0000;
        float acceleration;
        float speed;
        uint32_t position;
        uint8_t dir;
        uint8_t lane;

} RealTime;

typedef struct MessageType{
	uint8_t priority;
	uint8_t msgCategory;
	uint32_t count;
} MsgType;


typedef struct VehicelInformation{

	uint8_t type;
	uint8_t vehicle_id[4];
	uint16_t present = 0x0000;
	float acceleration;
	float speed;
	uint32_t position;
	uint8_t dir;
	uint8_t lane;
}VehicleInfo;


typedef struct MainFrame{

	MsgType message_type;
	VehicleInfo vehicle_info;

} Frame;

typedef struct finalPacket{
	std :: string ssid;
	std::vector<uint8_t> frameBufVendor;
} FinalBeacon;

//


/* Set Vehicle Properties on the Frame */

void setVehicleSpeed(MainFrame *frame,float speed);

void setVehicleAcceleration(MainFrame *frame,float acceleration);

void setVehicleType(MainFrame *frame,uint8_t type);

void setVehiclePosition(MainFrame *frame,uint32_t pos);

void setVehicleDirection(MainFrame *frame,uint8_t dir);

void setVehicleLane(MainFrame *frame,uint8_t lane);

void setVehicleID(MainFrame *frame,uint8_t id[4]);



void setMessagePriority(MainFrame *frame,uint8_t priority);

void setMsgCategory(MainFrame *frame,uint8_t msgCategory);

void setCount(MainFrame *frame, uint32_t count);

void realTimeUpdate(MainFrame *frame,RealTime * realtime);

void beaconFinalize(MainFrame *frame ,FinalBeacon *finalBeacon,Tins::PacketSender *sender);


/*
 *
 * Get Vehicle Properties
 *
 *
 * */

uint8_t getVehicleType(MainFrame *frame);

float getVehicleSpeed(MainFrame *frame);

float getVehicleAcceleration(MainFrame *frame);

uint8_t getVehicleDirection(MainFrame *frame);

uint8_t getVehicleLane(MainFrame *frame);

uint8_t *getVehicleID(MainFrame *frame);

uint32_t getVehiclePosition(MainFrame *frame);

// data converting to the finalpacket and put into the Dot11BeaconFrame//

void mainFrameToFinalBeacon(MainFrame *frame ,FinalBeacon *finalBeacon);

char getMessagePriority(MainFrame *frame);

uint8_t getMessageCategory(MainFrame *frame);

uint32_t getMessageCount(MainFrame *frame);








