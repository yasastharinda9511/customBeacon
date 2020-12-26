
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


void realTimeUpdate(MainFrame *Mframe,RealTime * realtime){
	
	setMessagePriority(Mframe,realtime->priority);
	setMsgCategory(Mframe,realtime->msgCategory);
	realtime->count+=1;
	setCount(Mframe, realtime->count);
	setVehicleSpeed(Mframe,realtime->speed);
	setVehicleAcceleration(Mframe,realtime->acceleration);
	setVehicleType(Mframe, realtime->type);
	setVehiclePosition(Mframe,realtime->position);
	setVehicleDirection(Mframe,realtime->dir);
	setVehicleLane(Mframe,realtime->lane);
	setVehicleID(Mframe,realtime->vehicle_id);
	
}

void beaconFinalize(MainFrame *Mframe ,FinalBeacon *fbeacon,Tins::PacketSender *sender){
	Tins :: Dot11Beacon beacon;
	mainFrameToFinalBeacon(Mframe ,fbeacon);
	beacon.addr1(Tins::Dot11::BROADCAST);
	beacon.addr2("00:01:02:03:04:05");
	beacon.addr3(beacon.addr2());
	beacon.ssid(fbeacon->ssid);
	beacon.vendor_specific(Tins :: Dot11ManagementFrame:: vendor_specific_type("00:45:23",fbeacon->frameBufVendor));
	
	Tins::RadioTap packt= Tins :: RadioTap()/beacon;

    

    Tins::NetworkInterface iface("wlan0");
    sender->send(packt, iface);
	
	
}

void setVehicleSpeed(MainFrame *frame,float speed){

	frame->vehicle_info.present |= VEHICLE_SPEED_FLAG;
	frame->vehicle_info.speed = speed;

}

void setVehicleAcceleration(MainFrame *frame,float acceleration){

	frame->vehicle_info.present |= VEHICLE_ACCEL_FLAG;
	frame->vehicle_info.acceleration = acceleration;

}

void setVehicleType(MainFrame *frame,uint8_t type){

	frame->vehicle_info.present |= VEHICLE_TYPE_FLAG;
	frame->vehicle_info.type = type;

}

void setVehiclePosition(MainFrame *frame,uint32_t pos){

	frame->vehicle_info.present |= VEHICLE_POS_FLAG;
	frame->vehicle_info.position = pos;

}

void setVehicleDirection(MainFrame *frame,uint8_t dir){

	frame->vehicle_info.present |= VEHICLE_DIR_FLAG;
	frame->vehicle_info.dir = dir;

}

void setVehicleLane(MainFrame *frame,uint8_t lane){

	frame->vehicle_info.present |= VEHICLE_LANE_FLAG;
	frame->vehicle_info.lane = lane;

}


void setVehicleID(MainFrame *frame,uint8_t id[4]){

	frame->vehicle_info.present |= VEHICLE_ID_FLAG;
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

uint8_t *getVehicleID(MainFrame *frame){
	uint8_t *ptr = &(frame->vehicle_info.vehicle_id[0]);
	return ptr;
}

uint32_t getVehiclePosition(MainFrame *frame){
	return  frame->vehicle_info.position;
}

//set Message Properties //
// important //
void setMessagePriority(MainFrame *frame,uint8_t priority){

	switch(priority){
		case(PRIORITY_1):
			frame->message_type.priority='1';
			break;
		case(PRIORITY_2):
			frame->message_type.priority='2';
			break;
		case(PRIORITY_3):
			frame->message_type.priority='3';
			break;
		case(PRIORITY_4):
			frame->message_type.priority='4';
			break;
		default:
			frame->message_type.priority='1';
			break;
	}
}

void setMsgCategory(MainFrame *frame,uint8_t msgCategory){
	frame->message_type.msgCategory = msgCategory;

}

void setCount(MainFrame *frame, uint32_t count){
	frame->message_type.count=count;
}


// get  Message properties //

char getMessagePriority(MainFrame *frame){
	return frame->message_type.priority;

}

uint8_t getMessageCategory(MainFrame *frame){
	return frame->message_type.msgCategory;
}

uint32_t getMessageCount(MainFrame *frame){
	return frame->message_type.count;
}


void mainFrameToFinalBeacon(MainFrame *frame ,FinalBeacon *finalBeacon){
	finalBeacon->frameBufVendor.clear();
	finalBeacon->ssid = "";
	finalBeacon->ssid += (char)getMessagePriority(frame);
	finalBeacon->ssid += (char) getMessageCategory(frame);

	uint32_t BeaconCount = getMessageCount(frame);
	finalBeacon->ssid +=  (char)((BeaconCount>>24 & 0xff));
	finalBeacon->ssid +=  (char)((BeaconCount>>16 & 0xff));
	finalBeacon->ssid +=  (char)((BeaconCount>>8 & 0xff));
	finalBeacon->ssid +=  (char)((BeaconCount>>0 & 0xff));


	finalBeacon->frameBufVendor.push_back(frame->vehicle_info.present>>8 & 0xff);
	finalBeacon->frameBufVendor.push_back(frame->vehicle_info.present>>0 & 0xff);

	//std:: cout <<"SSID is :"<< finalBeacon->ssid<<std :: endl ;

	for(int i=15; i>=0; i--){
		switch(frame->vehicle_info.present & 0x0001<< i){
			case(VEHICLE_TYPE_FLAG):
				{
				//std:: cout <<"(VEHICLE_TYPE_FLAG :"<< getVehicleType(frame) <<std :: endl ;
				finalBeacon->frameBufVendor.push_back(getVehicleType(frame));
				break;
				}
			case(VEHICLE_ID_FLAG):
				{
				uint8_t *addr=getVehicleID(frame);
				//std:: cout <<"(VEHICLE_ID_FLAG :"<< *(addr) <<std :: endl ;
				finalBeacon->frameBufVendor.push_back(*addr);
				finalBeacon->frameBufVendor.push_back(*(addr+1));
				finalBeacon->frameBufVendor.push_back(*(addr+2));
				finalBeacon->frameBufVendor.push_back(*(addr+3));
				break;
				}
			case(VEHICLE_SPEED_FLAG):
				{
				//std:: cout <<"(VEHICLE_SPEED__FLAG :"<<std :: endl ;
				float  vSpeed = getVehicleSpeed(frame);
				uint8_t *speed =(uint8_t*) (&vSpeed);
				finalBeacon->frameBufVendor.push_back(*speed);
				finalBeacon->frameBufVendor.push_back(*(speed+1));
				finalBeacon->frameBufVendor.push_back(*(speed+2));
				finalBeacon->frameBufVendor.push_back(*(speed+3));
				break;
				}
			case(VEHICLE_ACCEL_FLAG):
				{
				//std:: cout <<"VEHICLE_ACCL_FLAG :"<<std :: endl ;
				float  vAccl = getVehicleAcceleration(frame);
				uint8_t *acceleration =(uint8_t*) (&vAccl);
				finalBeacon->frameBufVendor.push_back(*acceleration);
				finalBeacon->frameBufVendor.push_back(*(acceleration+1));
				finalBeacon->frameBufVendor.push_back(*(acceleration+2));
				finalBeacon->frameBufVendor.push_back(*(acceleration+3));
				break;
				}
			case(VEHICLE_POS_FLAG):
				{
				//std:: cout <<"VEHICLE_POS_FLAG :"<<std :: endl ;
                		uint32_t cPos = getVehiclePosition(frame);
                		finalBeacon->frameBufVendor.push_back((uint8_t)(cPos>>24 & 0xff));
                		finalBeacon->frameBufVendor.push_back((uint8_t)(cPos>>16 & 0xff));
                		finalBeacon->frameBufVendor.push_back((uint8_t)(cPos>>8 & 0xff));
                		finalBeacon->frameBufVendor.push_back((uint8_t)(cPos>>0 & 0xff));
                		break;
				}
			case(VEHICLE_DIR_FLAG):
				{
				//std:: cout <<"VEHICLE_DIR_FLAG :"<<std :: endl ;
                		uint8_t cDir = getVehicleDirection(frame);
                		finalBeacon->frameBufVendor.push_back(cDir);
				break;
				}
			case(VEHICLE_LANE_FLAG):
				{
				//std:: cout <<"(VEHICLE_LANE_FLAG :"<<std :: endl ;
				uint8_t cLane = getVehicleDirection(frame);
                                finalBeacon->frameBufVendor.push_back(cLane);
				break;
				}
			case(VEHICLE_STATUS_FLAG):
				{
				std::cout<<"IN"<<std::endl;
				break;
				}
			// we can add more fieds 

		}
	}

}
