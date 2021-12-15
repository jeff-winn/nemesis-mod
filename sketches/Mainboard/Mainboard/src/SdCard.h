#ifndef SD_CARD_H
#define SD_CARD_H

#include <IniFile.h>
#include <SD.h>

class SdCard {
    public:
        SdCard(uint32_t csPin, uint32_t detPin);

        void init();
        bool detected();

        IniFile openIni();        

    private:
        uint32_t m_csPin;
        uint32_t m_detPin;
        bool m_started;
};

// Grants access to the SD card.
extern SdCard Sdc;

#endif /* SD_CARD_H */