## Initialize the CLI
```
arduino-cli.exe config init
arduino-cli.exe core update-index --config-file ..\..\arduino-cli.yaml
```

## Install the cores required
```
arduino-cli.exe core install arduino:samd --config-file ..\..\arduino-cli.yaml
arduino-cli.exe core install adafruit:samd --config-file ..\..\arduino-cli.yaml
```

## Compile the product
```
arduino-cli.exe compile -b adafruit:samd:adafruit_feather_m0 --config-file ..\..\arduino-cli.yaml --build-properties "build.extra_flags=-DF_CPU=48000000L -DARDUINO=10808 -DARDUINO_ARCH_SAMD -DARDUINO_SAMD_ZERO -DARM_MATH_CM0PLUS -DADAFRUIT_FEATHER_M0 -D__arm__ -D__SAMD21G18A__ -D__RELEASE__" --build-path C:\Users\jeffw\Code\Nemesis-Mod\build ..\Nemesis-Mod
```