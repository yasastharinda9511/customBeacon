
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
/*void setFrameValue(MainFrame *frame,uint8_t dataPosition,uint8_t data){
	
	 frame->frameBufVendor[dataPosition] = data;
	
}*/

void setVehicleSpeed(MainFrame *frame,float speed){
	
	frame->vehicle_info.speed = speed;
	
}

void setVehicleAcceleration(MainFrame *frame,float acceleration){
	
	frame->vehicle_info.acceleration = acceleration;
	
}

void setVehicleType(MainFrame *frame,uint8_t type){
	
	frame->vehicle_info.type = type;
	
}

void setVehiclePosition(MainFrame *frame,uint32_t pos){
	
	frame->vehicle_info.pos = pos;
	
}

void setVehicleDirection(MainFrame *frame,uint8_t dir){
	
	frame->vehicle_info.dir = dir;
	
}

void setVehicleLane(MainFrame *frame,uint8_t lane){
	
	frame->vehicle_info.lane = lane;
	
}


void setVehicleID(MainFrame *frame,uint8_t id[4]){
	
	frame->vehicle_info.vehicle_id[0] = id[0];
	frame->vehicle_info.vehicle_id[1] = id[1];
	frame->vehicle_info.vehicle_id[2] = id[2];
	frame->vehicle_info.vehicle_id[3] = id[3];
	
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







