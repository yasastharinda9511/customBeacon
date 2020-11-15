# customBeacon

The main purpose of maintaining this repository is to forge custom beacons using C/C++. We used Raspberry pi 3/B+ along with the ALFA  AWUS036NHA wifi adapter. Below figure illustrates the our test bench which we had used to deploy our codes and test it.Normally wifi beacons are considered as low priority level management frames Therefore these frames are treated as no QoS based frame. To enable the QoS inside the frame we used SSID frame inside the beacon frame as QOS filed and access that filed inside the linux wireless driver level and treated as qos based data frame (To achieve that you have to use this source codes along with the customized ath9k_htc driver.) 
   
   
