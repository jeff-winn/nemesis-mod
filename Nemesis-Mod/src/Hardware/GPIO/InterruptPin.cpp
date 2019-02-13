#include "InterruptPin.h"

InterruptPin::InterruptPin(uint8_t id, uint8_t interruptId, HAL* p_hal) 
    : Pin(id, p_hal) {
    m_interruptId = interruptId;
}

void InterruptPin::init(void (*onStateChangedCallback)(void), InterruptMode mode) {
    hal->pinModeSafe(m_Id, PinMode::Read);
    hal->attachInterruptSafe(m_interruptId, onStateChangedCallback, mode);
}

int InterruptPin::read() {
    return hal->digitalReadSafe(m_Id);
}