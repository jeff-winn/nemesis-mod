#ifndef SD_CARD_H
#define SD_CARD_H

#include <ArduinoJson.h>

/*
A mechanism which is capable of interacting with the SD card file system.
*/
class SdCard {
    public:
        SdCard(uint8_t csPin, uint8_t detPin) : m_csPin(csPin), m_detPin(detPin) { }

        // Initializes the instance.
        void init();

        // Identifies whether an SD card is detected.
        bool detected() const;

        // Reads the configuration file into memory.
        DynamicJsonDocument readConfig() const;        

    private:
        uint8_t m_csPin;
        uint8_t m_detPin;
        bool m_started;
};

// Grants access to the SD card.
extern SdCard Sdc;

#endif /* SD_CARD_H */