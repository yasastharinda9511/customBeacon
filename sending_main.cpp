#include <tins/tins.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "customBeacon.h"



int main() {

	MainFrame  Mframe1;
	MainFrame *Mframe= &Mframe1;

	Tins :: Dot11Beacon beacon;

	FinalBeacon finalbeacon;
	FinalBeacon *fbeacon = &finalbeacon;

	uint32_t count =0x41414141;
	uint8_t vehicleID [4] ={0x41,0x42,0x43,0x44};

	setMessagePriority(Mframe,PRIORITY_4);
	setMsgCategory(Mframe,EMERGENCY_VEHICLE_MESSAGE);
	setCount(Mframe, count);


	setVehicleSpeed(Mframe,50);
	setVehicleAcceleration(Mframe,50);
	setVehicleType(Mframe, VEHICLE_TYPE_AMBULANCE);
	setVehiclePosition(Mframe,0x00000041);
	setVehicleDirection(Mframe,0x41);
	setVehicleLane(Mframe,0x41);
	setVehicleID(Mframe,vehicleID);

	mainFrameToFinalBeacon(Mframe ,fbeacon);
	//Mframe->frameBufVendor[0]=0x05;
        // Dot11Beacon beacon;
        // Make this a broadcast frame. Note that Dot11::BROADCAST
        // is just the same as "ff:ff:ff:ff:ff:ff"
        beacon.addr1(Tins::Dot11::BROADCAST);
        // We'll set the source address to some arbitrary address
        beacon.addr2("00:01:02:03:04:05");
        // Set the bssid, to the same one as above
        beacon.addr3(beacon.addr2());

        // Let's add an ssid option
        beacon.ssid(fbeacon->ssid);
        // Our current channel is 8
        //beacon.ds_parameter_set(8);
        // This is our list of supported rates:
        //beacon.supported_rates({ 1.0f, 5.5f, 11.0f });

        // Encryption: we'll say we use WPA2-psk encryption
        //beacon.rsn_information(RSNInformation::wpa2_psk());
        beacon.vendor_specific(Tins :: Dot11ManagementFrame:: vendor_specific_type("00:45:23",fbeacon->frameBufVendor));
        // The beacon's ready to be sent!
        Tins::RadioTap packt= Tins :: RadioTap()/beacon;

        Tins::PacketSender sender;

        Tins::NetworkInterface iface("wlan0");
	std:: cout << "Priority of the frame is :"<< Mframe->message_type.priority <<std::endl;
	std:: cout << "MessageType of the frame is :"<< Mframe->message_type.msgCategory <<std::endl;
	std:: cout << "Count of the frame is :"<< Mframe->message_type.count <<std::endl;
        while(1){
                sender.send(packt, iface);
                usleep(100000);
        }

}

