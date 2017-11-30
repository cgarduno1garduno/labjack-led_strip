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
		$ install libusb exodriver --universal

To compile and run in terminal:
	$ gcc lj.c u3.c labjackusb.c -o cff_c `pkg-config --libs --cflags libusb-1.0`
	$ ./cff_c

For LabJack circuit
	using GND, FIO0, FIO1
********************************************************************************/
#include <unistd.h>
#include <stdint.h>
// this library is included during compilation 
//#include <libusb-1.0/libusb.h> 
#include "Adafruit_NeoPixel.h" // c++ file
#include "u3.h"
#include "labjackusb.h"

int main() {
	// Initialize vars
	HANDLE hDevice;
	u3CalibrationInfo caliInfo;
	int localID;
	long error;


	// Open first available usb-connected U3 and check for valid connection
	localID = -1;
	hDevice = openUSBConnection(localID);
	if (hDevice == NULL) {
		goto done;
		printf("Invalid connection\n");
	}

	// Get calibration from U3
	//error = getCalibrationInfo(hDevice, &caliInfo);
	//if (error < 0) {
	//	goto close;
	//	printf("error < 0\n");
	//}

	// @param1: u3 device
	// @param2: ConfigIO, configure on first call then set to 0 after
	// @param3: channel
	// @param4: value of channel, 0 = low, 1 = high
	eDO(hDevice, 1, 0, 1);

	done:
		return 0;

	close:
		if (error < 0)
			printf("Received an error code of %ld\n", error);
		closeUSBConnection(hDevice);
}



/*
	Functions
		Load Labjack
		iterate through eccentricities
		iterate through frequencies
		flicker 

*/





