/********************************************************************************
@author Cristopher Garduno Luna
@email  garduno.cris@gmail.com

Using SparkFun's WS2812 Addressable LED Strip with LabJack
	https://www.sparkfun.com/products/12025
	GRB, 800 KHz Bitstream (from documentation)
	60 LEDs per meter

Labjack C/C++ Exodriver Installer
	https://labjack.com/support/software/installers/exodriver
	need to have libusb installed:
		$ pip install libusb

	pkg-config --cflags --libs /usr/local/Cellar/libusb/1.0.21/lib/pkgconfig/libusb-1.0.pc

To compile and run in terminal:
	$ g++ -x c labjackusb.c u3.c -x c++ lj.cpp Adafruit_NeoPixel.cpp -o cff `pkg-config --libs --cflags libusb-1.0`
	$ ./cff
********************************************************************************/
#include <iostream>
#include <unistd.h>
#include "Adafruit_NeoPixel.h"

// C files 
#include "labjackusb.h"
#include "u3.h"
#include <libusb-1.0/libusb.h>

int main() {
	// Initialize params
	HANDLE hDevice;
	u3CalibrationInfo caliInfo;
	int localID;
	long error;

	// establish connection to u3
	localID = -1;
	hDevice = openUSBConnection(localID);
	if (hDevice == NULL) {
		printf("Invalid connection\n");
	}

	eDO(hDevice, 1, 0, 1);

	return 0;
}



/*
	Load labjack

	Functions
		Load Labjack
		iterate through eccentricities
		iterate through frequencies
		flicker 

*/





