# labjack-led_strip
Using a LabJack to control a SparkFun [LED Strip](https://www.sparkfun.com/products/12025)

Compile and run with 
```
$ gcc lj.c u3.c labjackusb.c -o cff_c `pkg-config --libs --cflags libusb-1.0`
$ ./cff_c
```
