

#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

#define EMERGENCY_VEHICLE_MESSAGE 0x01
#define LANE_CHANGING_MESSAGE 0x02
#define BASIC_SAFETY_MESSAGE 0x03
#define SUDDEN_BRAKE_MESSAGE 0x04





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
	uint8_t frameBufVendor[50]; // this is a frame buffer for store vehicle data in vendor elements

} Frame;






/* Set Vehicle Properties on the Frame */


void setFrameValue(MainFrame *frame,uint8_t dataPosition,uint8_t data);











/* Get Vehicle Properties */

uint8_t getVehicleType(MainFrame *frame);

float getVehicleSpeed(MainFrame *frame);

float getVehicleAcceleration(MainFrame *frame);

uint8_t getVehicleDirection(MainFrame *frame);

uint8_t getVehicleLane(MainFrame *frame);











