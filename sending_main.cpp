#include <tins/tins.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#include "customBeacon.h"



int main() {
	time_t startTime = time(NULL);

	MainFrame  Mframe1;
	MainFrame *Mframe= &Mframe1;

	

	FinalBeacon finalbeacon;
	FinalBeacon *fbeacon = &finalbeacon;

        
	Tins::PacketSender sender1;
	Tins::PacketSender *sender = &sender1;
	
	
	RealTime currentData1;
	RealTime *currentData = &currentData1;
	currentData->count=0;
	currentData->vehicle_id[0] = 'A';
	currentData->vehicle_id[1] = 'B';
	currentData->vehicle_id[2] = 'C';
	currentData->vehicle_id[3] = 'D';
	
	time_t currentTime;
        while(1){
		currentTime = time(NULL);
		currentData->priority = PRIORITY_1;
		currentData->msgCategory = EMERGENCY_VEHICLE_MESSAGE;
		currentData->type = VEHICLE_TYPE_AMBULANCE;
		currentData->present = 0x0000;
		currentData->acceleration = 50;
		currentData->speed = 100;
		currentData->position = 0x00000041;
		currentData->dir = 0x42;
		currentData->lane = 0x43;
		
		
		realTimeUpdate(Mframe,currentData);
		beaconFinalize(Mframe,fbeacon,sender);
                
                usleep(100000);
		if((currentTime-startTime)>20){
			return 0;
		}
        }

}

