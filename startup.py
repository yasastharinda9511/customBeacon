import os
import time
import threading

def configureInterfaces():
    os.system("sudo python3 configure.py")

def rx():
    os.system("sudo ./rx.o")
    

def tx():
    time.sleep(2)
    os.system("sudo ./tx.o")

#waiting for start command


#Configuring interfaces
configureInterfaces()

time.sleep(2)

#start receiving and transmission

rx_thread = threading.Thread(target = rx,args = ())
rx_thread.start()
print("rx started")
tx_thread = threading.Thread(target = tx,args = ())
tx_thread.start()
print("tx started")

time.sleep(5)

rx_thread.join()
tx_thread.join()
print("All finshed still TX RX are running .....")








