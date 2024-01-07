# Nemesis Mod
It started off as me just wanting to play with an Arduino while repurposing some old .NET Gadgeteer hardware I had laying around the house. It turned into quite a bit more than that over the months that I worked on it. Hopefully the source code will help someone interested in replicating the success I had with my project with their own. Happy coding!

| Branch | Status |
| ------ | -------------|
| master | [![CI](https://github.com/jeff-winn/Nemesis-Mod/actions/workflows/ci.yaml/badge.svg)](https://github.com/jeff-winn/Nemesis-Mod/actions/workflows/ci.yaml) [![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=nemesis-mod&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=nemesis-mod) |

## Setting up your environment
Because this project requires the use of symbolic links, you will need to use the command line to clone the repository. Visual Studio Code can do it, but it does not permit symbolic links by default.

```shell
git clone -c core.symlinks=true 
```

## Hardware Requirements
These are the boards and hardware being used by the project:
- [Adafruit Feather M4 Express](https://www.adafruit.com/product/3857) - Mainboard sketch
- [Adafruit Micro SD SPI or SDIO Card Breakout Board](https://www.adafruit.com/product/4682)
- [Tactile Button Switch (6mm square, 5mm tall)](https://www.adafruit.com/product/367)
- [Pololu Dual G2 High-Power Motor Driver 18v18 Shield for Arduino](https://www.pololu.com/product/2515)
- [Pololu G2 High-Power Motor Driver 18v17](https://www.pololu.com/product/2991)
- [Pololu 5V, 500mA Step-Down Voltage Regulator](https://www.pololu.com/product/2843)

### Optional Hardware
- [Adafruit Feather nRF52840 Express](https://www.adafruit.com/product/4062) - Bluetooth sketch
- [MaxAmps LiPo 3250 3S 11.1v Battery Pack](https://www.maxamps.com/lipo-3250-3s-11-1v-battery-pack)

## Bluetooth Support
If you wish to use the Bluetooth connectivity included with this device, please see the Wiki page.
