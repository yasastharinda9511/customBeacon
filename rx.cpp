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
	//std:: cout << "frame is :"<< &pdu << std::endl;
    /*const IP &ip = pdu.rfind_pdu<IP>();
    const TCP &tcp = pdu.rfind_pdu<TCP>();
    std::cout << ip.src_addr() << ':' << tcp.sport() << " -> " 
         << ip.dst_addr() << ':' << tcp.dport() << std::endl;
         * 
         * */
    std::vector<RadioTap> vec(1, RadioTap());
    //std::vector<EthernetII> vec(1, EthernetII());
    //std::vector<Dot11> vec(1, Dot11());
    
    writer.write(vec.begin(), vec.end());
    writer.write(vec[0]);
    
    
    return true;
}


int main() {
    

	config.set_promisc_mode(true);
	config.set_snap_len(1000);

	
	
	PDU *some_pdu = sniffer.next_packet();
	std:: cout << "frame is :"<< some_pdu << std::endl;
	
	
	//Tins::RadioTap();
	
	
    PacketWriter *w= &writer;
    
    
	//sniffer.sniff_loop(callback);
	
	while(Packet pkt = sniffer.next_packet()) {
		//pkt.pdu(); // <- pdu
		//pkt.timestamp(); // <- timestamp
		//std:: cout << "timestamp is :"<< pkt.timestamp(); << std::endl;
		
		writer.write(pkt);
		
	}
    
    
    //"10:F0:05:63:B7:DF"
    //std::vector<RadioTap> vec(1, RadioTap());
    //writer.write(vec.begin(), vec.end());
    
    


    
    
    
}
