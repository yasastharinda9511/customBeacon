# customBeacon

## Introduction

  The main purpose of maintaining this repository is to forge custom beacons using C/C++ API called as `libtins`. We used Raspberry pi 3/B+ along with the ALFA  AWUS036NHA wifi adapter. Below figure illustrates the our test bench which we had used to deploy our codes and test it.Normally wifi beacons are considered as low priority level management frames Therefore these frames are treated as no QoS based frame. To enable the QoS inside the frame we used SSID frame inside the beacon frame as QOS filed and access that filed inside the linux wireless driver level and treated as qos based data frame (To achieve that you have to use this source codes along with the customized ath9k_htc driver.) 
  
![1](https://user-images.githubusercontent.com/37435024/99192107-10c7b300-2797-11eb-9d43-1f1b5c9992b2.jpg)

## Architecture of our project

  We devided our project into 4 layes and identify what are the modifictaions we have to do in each layer. This reprository only describe the changes that we have made inside the application layer(Basically not changes piece of code running inside the application layer).  

![20201023_231157](https://user-images.githubusercontent.com/37435024/99192280-11ad1480-2798-11eb-962e-691e9c487041.jpg)

## Beacon Frame Architecture

  Like mentioned in the introductoion of the reprository to achieve the QoS enable beacon frames Qos field should be inside the frame. Actually beacon frames does not have that feature therefore we made some our own standard to use ssid field as our QoS filed

![Beacon_2](https://user-images.githubusercontent.com/37435024/99192577-87fe4680-2799-11eb-848b-5aab7ba74dc6.jpg)

![ssid_2](https://user-images.githubusercontent.com/37435024/99192993-065be800-279c-11eb-81ff-b1396528fe1f.jpg)


                            
