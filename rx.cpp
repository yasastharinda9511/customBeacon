#include <vector>
#include <tins/tins.h>
#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctime>


using namespace Tins;


PacketWriter writer("../tmp_pcap/rx_test.pcap", DataLinkType<RadioTap>());



int main() {
	time_t startTime = time(NULL);
    
	SnifferConfiguration config;
	config.set_promisc_mode(true);
	config.set_rfmon(true);
	config.set_snap_len(1000);
	config.set_filter("type mgt subtype beacon");
	Sniffer sniffer("monRX",config);

	
    PacketWriter *w= &writer;
	time_t currentTime;
	while(Packet pkt = sniffer.next_packet()) {
		currentTime = time(NULL);
		PDU *pdu;
		pdu = pkt.pdu();
		if(pdu->find_pdu<Dot11Beacon>()){
			writer.write(pkt);
		}
		if((currentTime-startTime)>20){
			return 0;
		}
		
		
	}
    

}
