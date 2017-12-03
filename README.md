# labjack-led_strip
Using a LabJack to control a SparkFun [LED Strip](https://www.sparkfun.com/products/12025)

Compile and run with 
```
$ g++ -x c labjackusb.c u3.c -x c++ lj.cpp Adafruit_NeoPixel.cpp -o cff `pkg-config --libs --cflags libusb-1.0`
$ ./cff_c
```
