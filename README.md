## Build Status
This project currently integrates with AppVeyor CI to build the Makefile (using MinGW) on their virtual machines automatically upon check-in.

Master | Current
------------ | -------------
![Master Build Status](https://ci.appveyor.com/api/projects/status/85ad7mn4lbf9lewh/branch/master?svg=true) | ![Current Build Status](https://ci.appveyor.com/api/projects/status/85ad7mn4lbf9lewh?svg=true)


## Hardware Requirements
These are the boards and hardware being used by the project.
- [Nerf Rival Nemesis MXVII-10K](https://shop.hasbro.com/en-us/product/nerf-rival-nemesis-mxvii-10-k-blue:04E71588-5056-9047-F5B8-940FC9A5A209)
- [Adafruit METRO 328](https://www.adafruit.com/product/2488)
- [Breadboard](https://www.adafruit.com/product/64)
- [Breadboard Trim Potentiometer (10k)](https://www.adafruit.com/product/356)
- [Pololu Dual G2 High-Power Motor Driver 18v18 Shield for Arduino](https://www.pololu.com/product/2515)
- [.NET Gadgeteer breakout board](http://www.ctr-electronics.com/breakoutmodule.html)
- [.NET Gadgeteer Button module](https://old.ghielectronics.com/catalog/product/274)

## Development Environment
This is the toolset that is currently being used to write the code included within the src folder within this repository.
- Visual Studio Code
  - C/C++ extension
- MacOS
  - XCode command line tools
- Windows
  - MinGW (mingw32-base-bin, mingw32-gcc-g++-bin, msys-base-bin)

### Dependencies
Below are the dependencies that are being used by the project.
- [Pololu Dual G2 High-Power Motor Driver Library for Arduino](https://github.com/pololu/dual-g2-high-power-motor-shield)
