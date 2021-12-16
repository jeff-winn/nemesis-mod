#include "SdCard.h"

SdCard Sdc = SdCard(A2, A1);

SdCard::SdCard(uint32_t csPin, uint32_t detPin) {
    m_csPin = csPin;
    m_detPin = detPin;
}

void SdCard::init() {
    if (m_started) {
        return;
    }

    pinMode(m_detPin, INPUT);
    pinMode(m_csPin, OUTPUT);

    auto success = SD.begin(m_csPin);
    if (success) {
        m_started = true;
    }
}

bool SdCard::detected() {
    return digitalRead(m_detPin) != 0;
}

IniFile SdCard::openIni() {
    IniFile result = IniFile(BLASTER_CONFIG_FILE);
    result.open();
    
    return result;
}