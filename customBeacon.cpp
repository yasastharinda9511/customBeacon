
#include "customBeacon.h"
#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>


/* Set Vehicle Properties on the Frame */


/* 
 * this method want current frame, value to be set and the position
 * 
 * */
void setFrameValue(MainFrame *frame,uint8_t dataPosition,uint8_t data){
	
	 frame->frameBufVendor[dataPosition] = data;
	
}







/* Get Vehicle Properties */

uint8_t getVehicleType(MainFrame *frame){
	return frame->vehicle_info.type;
}

float getVehicleSpeed(MainFrame *frame){
	return frame->vehicle_info.speed;
}

float getVehicleAcceleration(MainFrame *frame){
	return frame->vehicle_info.acceleration;
}

uint8_t getVehicleDirection(MainFrame *frame){
	return frame->vehicle_info.dir;
}

uint8_t getVehicleLane(MainFrame *frame){
	return frame->vehicle_info.lane;
}







