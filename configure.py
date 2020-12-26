import os
import time
os.system("iwconfig")
#time.sleep(1)
os.system("sudo airmon-ng check kill")
#time.sleep(5)
os.system("sudo airmon-ng start wlan0")
#time.sleep(2)
#############################################################################
os.system("sudo iw wlan0 interface add monTX type monitor")
#time.sleep(1)

os.system("sudo airmon-ng start monTX")
#time.sleep(1)

os.system("sudo iwconfig monTX channel 11")
#time.sleep(1)
#############################################################################
os.system("sudo iw wlan0 interface add monRX type monitor")
#time.sleep(1)

os.system("sudo airmon-ng start monRX")
#time.sleep(1)

os.system("sudo iwconfig monRX channel 11")
time.sleep(1)
#############################################################################

print("Configured Successfully")


