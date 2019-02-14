#include "InterruptPin.h"

InterruptPin::InterruptPin(uint8_t id, uint8_t interruptId, HardwareAccessLayer* p_hal) 
    : Pin(id, p_hal) {
    m_interruptId = interruptId;
}

void InterruptPin::init(void (*onStateChangedCallback)(void), InterruptMode mode) {
    hardware->pinModeSafe(m_Id, PinMode::Read);
    hardware->attachInterruptSafe(m_interruptId, onStateChangedCallback, mode);
}

int InterruptPin::read() {
    return hardware->digitalReadSafe(m_Id);
}