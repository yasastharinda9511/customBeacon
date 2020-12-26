all: 
	g++ rx.cpp -o rx.o -ltins
	g++ sending_main.cpp customBeacon.cpp -o tx.o -ltins
	g++ configure.cpp -o configure.o