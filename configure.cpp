#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	
	system("iwconfig");
	system("sudo airmon-ng check kill");
	system("sudo airmon-ng start wlan0");
////////////////////////////////////////////////////////////////////
	system("sudo iw wlan0 interface add monTX type monitor");
	system("sudo airmon-ng start monTX");
	system("sudo iwconfig monTX channel 11");
////////////////////////////////////////////////////////////////////
	//system("sudo iw wlan0 interface add monRX type monitor");
	//system("sudo airmon-ng start monRX");
	system("sudo iwconfig wlan0mon channel 11");
	printf("Configured Successfully \n");
	
}









