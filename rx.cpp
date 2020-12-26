#include <vector>
#include <tins/tins.h>
#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctime>


using namespace Tins;






int main() {
	
	
	
	time_t startTime = time(NULL);
	struct tm *timeinfo;
	char buffer[80];
	time(&startTime);
	timeinfo = localtime(&startTime);
	strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
	std::string str(buffer);
	
	PacketWriter writer("/home/pi/tmp_pcap/"+str+".pcap", DataLinkType<RadioTap>());
    
	SnifferConfiguration config;
	config.set_promisc_mode(true);
	config.set_rfmon(true);
	config.set_snap_len(1000);
	config.set_filter("type mgt subtype beacon");
	Sniffer sniffer("wlan0mon",config);

	
    PacketWriter *w= &writer;
	time_t currentTime;
	while(Packet pkt = sniffer.next_packet()) {
		currentTime = time(NULL);
		PDU *pdu;
		pdu = pkt.pdu();
		if(pdu->find_pdu<Dot11Beacon>()){
			writer.write(pkt);
		}
		if((currentTime-startTime)>60){
			return 0;
		}
		
		
	}
    

}
