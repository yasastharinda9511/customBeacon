
#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <tins/tins.h>

#define EMERGENCY_VEHICLE_MESSAGE 0x01
#define LANE_CHANGING_MESSAGE 0x02
#define BASIC_SAFETY_MESSAGE 0x03
#define SUDDEN_BRAKE_MESSAGE 0x04

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

=======
#define VEHICLE_TYPE_CAR 0x01
#define VEHICLE_TYPE_VAN 0x02
#define VEHICLE_TYPE_BUS 0x03
#define VEHICLE_TYPE_AMBULANCE 0x04


// Data Types
typedef struct MessageType{
	char priority;
	uint8_t messageType;
	uint32_t count;
} MsgType;


typedef struct VehicelInformation{

	uint8_t type;
	uint8_t vehicle_id[4];
	uint16_t present;
	float acceleration;
	float speed;
	uint32_t pos;
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



// data converting to the finalpacket and put into the Dot11BeaconFrame//

void mainFrameToFinalBeacon(MainFrame *frame ,FinalBeacon *finalBeacon ,Tins:: Dot11Beacon *beacon);












