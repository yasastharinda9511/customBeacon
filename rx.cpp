#include <vector>
#include <tins/tins.h>
#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


using namespace Tins;

SnifferConfiguration config;
Sniffer sniffer("mon1",config);
PacketWriter writer("../tmp_pcap/rx_test.pcap", DataLinkType<RadioTap>());


bool callback(const PDU &pdu) {
	
    std::vector<RadioTap> vec(1, RadioTap());
   
    writer.write(vec.begin(), vec.end());
    writer.write(vec[0]);
    
    
    return true;
}


int main() {
    

	config.set_promisc_mode(true);
	config.set_snap_len(1000);

	
    PacketWriter *w= &writer;
  
	//sniffer.sniff_loop(callback);
	
	while(Packet pkt = sniffer.next_packet()) {
		//pkt.pdu(); // <- pdu
		//pkt.timestamp(); // <- timestamp
		//std:: cout << "timestamp is :"<< pkt.timestamp(); << std::endl;
		
		writer.write(pkt);
		
	}
    

}
