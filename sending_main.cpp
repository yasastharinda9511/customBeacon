#include <tins/tins.h>
#include <iostream>
#include <unistd.h>
using namespace Tins;

int main() {
         Dot11Beacon beacon;
        // Make this a broadcast frame. Note that Dot11::BROADCAST
        // is just the same as "ff:ff:ff:ff:ff:ff"
        beacon.addr1(Dot11::BROADCAST);
        // We'll set the source address to some arbitrary address
        beacon.addr2("00:01:02:03:04:05");
        // Set the bssid, to the same one as above
        beacon.addr3(beacon.addr2());

        // Let's add an ssid option
        beacon.ssid("libtins");
        // Our current channel is 8
        //beacon.ds_parameter_set(8);
        // This is our list of supported rates:
        //beacon.supported_rates({ 1.0f, 5.5f, 11.0f });

        // Encryption: we'll say we use WPA2-psk encryption
        beacon.rsn_information(RSNInformation::wpa2_psk());
        beacon.vendor_specific();
        // The beacon's ready to be sent!
        RadioTap packt=RadioTap()/beacon;

        PacketSender sender;

        NetworkInterface iface("wlan0");
        while(1){
                sender.send(packt, iface);
                usleep(100000);
        }

}

