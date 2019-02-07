## Build Status
This project currently integrates with AppVeyor CI to build the Makefile (using MinGW) on their virtual machines automatically upon check-in.

Master | Current
------------ | -------------
![Master Build Status](https://ci.appveyor.com/api/projects/status/85ad7mn4lbf9lewh/branch/master?svg=true) | ![Current Build Status](https://ci.appveyor.com/api/projects/status/85ad7mn4lbf9lewh?svg=true)


## Hardware Requirements
These are the boards and hardware being used by the project.
- [Adafruit METRO 328](https://www.adafruit.com/product/2488)
- Breadboard
- [Pololu Dual G2 High-Power Motor Driver 18v18 Shield for Arduino](https://www.pololu.com/product/2515)
- [.NET Gadgeteer breakout board](http://www.ctr-electronics.com/breakoutmodule.html)
- [.NET Gadgeteer Button module](https://old.ghielectronics.com/catalog/product/274)

### Development Environment
This is the toolset that is currently being used to write the code included within the src folder within this repository.
- Visual Studio Code
  - C/C++ extension
  - MinGW (mingw32-base-bin, mingw32-gcc-g++-bin, msys-base-bin)

### Dependencies
Below are the dependencies that are being used by the project.
- [Arduino PWM Frequency Library](https://code.google.com/archive/p/arduino-pwm-frequency-library/downloads)
