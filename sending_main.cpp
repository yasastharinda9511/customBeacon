#include <tins/tins.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "customBeacon.h"



int main() {

	MainFrame  Mframe1;
	MainFrame *Mframe= &Mframe1;

	Mframe->message_type.priority = '1';
	Mframe->message_type.count = 20;
	Mframe->message_type.msgCategory = EMERGENCY_VEHICLE_MESSAGE;
	
	
	
	
	
	
	//Mframe->frameBufVendor[0]=0x05;
        // Dot11Beacon beacon;
        // Make this a broadcast frame. Note that Dot11::BROADCAST
        // is just the same as "ff:ff:ff:ff:ff:ff"
        //beacon.addr1(Dot11::BROADCAST);
        // We'll set the source address to some arbitrary address
        //beacon.addr2("00:01:02:03:04:05");
        // Set the bssid, to the same one as above
        //beacon.addr3(beacon.addr2());

        // Let's add an ssid option
        //beacon.ssid("libtins");
        // Our current channel is 8
        //beacon.ds_parameter_set(8);
        // This is our list of supported rates:
        //beacon.supported_rates({ 1.0f, 5.5f, 11.0f });

        // Encryption: we'll say we use WPA2-psk encryption
        //beacon.rsn_information(RSNInformation::wpa2_psk());
        //beacon.vendor_specific();
        // The beacon's ready to be sent!
        //RadioTap packt=RadioTap()/beacon;

        //PacketSender sender;

        //NetworkInterface iface("wlan0");
	std:: cout << "Priority of the frame is :"<< Mframe->message_type.priority <<std::endl;
	std:: cout << "MessageType of the frame is :"<< Mframe->message_type.msgCategory <<std::endl;
	std:: cout << "Count of the frame is :"<< Mframe->message_type.count <<std::endl;
        //while(1){
        //        sender.send(packt, iface);
        //        usleep(100000);
        //}

}

