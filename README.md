# About the Nemesis-Mod project...
It started off as me just wanting to play with an Arduino while repurposing some old .NET Gadgeteer hardware I had laying around the house. It turned into quite a bit more than that over the months that I worked on it. Hopefully the source code will help someone interested in replicating the success I had with my project with their own. Happy coding!

| Branch | Status |
| ------ | -------------|
| master | [![CI](https://github.com/jeff-winn/Nemesis-Mod/actions/workflows/ci.yaml/badge.svg)](https://github.com/jeff-winn/Nemesis-Mod/actions/workflows/ci.yaml) |

## Hardware Requirements
These are the boards and hardware being used by the project.
- [Nerf Rival Nemesis MXVII-10K](https://shop.hasbro.com/en-us/product/nerf-rival-nemesis-mxvii-10-k-blue:04E71588-5056-9047-F5B8-940FC9A5A209)
- [Adafruit Feather M4 Express](https://www.adafruit.com/product/3857) - Mainboard sketch
- [Adafruit Feather nRF52840 Express](https://www.adafruit.com/product/4062) - Bluetooth sketch
- [Adafruit I2C Non-Volatile FRAM Breakout](https://www.adafruit.com/product/1895)
- [Tactile Button Switch (6mm square, 5mm tall)](https://www.adafruit.com/product/367)
- [Pololu Dual G2 High-Power Motor Driver 18v18 Shield for Arduino](https://www.pololu.com/product/2515)
- [Pololu G2 High-Power Motor Driver 18v17](https://www.pololu.com/product/2991)
- [Pololu 5V, 500mA Step-Down Voltage Regulator](https://www.pololu.com/product/2843)

### Optional Hardware
- [MaxAmps LiPo 3250 3S 11.1v Battery Pack](https://www.maxamps.com/lipo-3250-3s-11-1v-battery-pack)
- There is a custom PCB designed to consolidate the wiring within the docs/kicad folder of this project.
