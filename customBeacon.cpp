
#include "customBeacon.h"



/* Set Vehicle Properties on the Frame */


/* 
 * this method want current frame, value to be set and the position
 * 
 * */
void setFrameValue(MainFrame *frame,uint8_t dataPosition,uint8_t data){
	
	frame->frameBufVendorPtr+dataPosition = data;
	
}







/* Get Vehicle Properties */

uint8_t getVehicleType(MainFrame *frame){
	return frame->vehicle_info.type;
}

float_t getVehicleSpeed(MainFrame *frame){
	return frame->vehicle_info.speed;
}

float_t getVehicleAcceleration(MainFrame *frame){
	return frame->vehicle_info.acceleration;
}

uint8_t getVehicleDirection(MainFrame *frame){
	return frame->vehicle_info.dir;
}

uint8_t getVehicleLane(MainFrame *frame){
	return frame->vehicle_info.lane;
}







