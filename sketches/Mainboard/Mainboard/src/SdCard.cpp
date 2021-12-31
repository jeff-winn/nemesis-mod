#include "SdCard.h"
#include <SD.h>

const String BLASTER_CONFIG_FILE = "blaster.cfg";
const SdCard g_Sdc = SdCard(A2, A1);

const SdCard& getSd() {
    return g_Sdc;
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

bool SdCard::detected() const {
    return digitalRead(m_detPin) != 0;
}

DynamicJsonDocument SdCard::readConfig() const {
    auto file = SD.open(BLASTER_CONFIG_FILE, FILE_READ);
    auto size = file.size();

    DynamicJsonDocument doc(size);  
    deserializeJson(doc, file);

    file.close();
    return doc;
}