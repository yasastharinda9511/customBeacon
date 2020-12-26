import os
import time

time.sleep(10)
print("Waiting for configuring......")
time.sleep(10)


os.system("iwconfig")
time.sleep(0.5)
os.system("sudo airmon-ng check kill")
time.sleep(10)
os.system("sudo airmon-ng start wlan0")
time.sleep(0.5)
os.system("sudo iw wlan0 interface add monTX type monitor")
time.sleep(0.5)
os.system("sudo airmon-ng start monTX")
time.sleep(0.5)

os.system("sudo iwconfig monTX channel 11")
time.sleep(0.5)

os.system("sudo iwconfig wlan0mon channel 11")
time.sleep(0.5)

print("Configured Successfully")




