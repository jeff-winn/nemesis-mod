#include "InterruptPin.h"

using namespace App::Hardware::GPIO;

InterruptPin::InterruptPin(uint8_t id, uint8_t interruptId) : Pin(id) {
    m_interruptId = interruptId;
}

void InterruptPin::init(void (*onStateChangedCallback)(void), InterruptMode mode) {
    hal->pinModeSafe(m_Id, PinMode::Input);
    hal->attachInterruptSafe(m_interruptId, onStateChangedCallback, mode);
}

int InterruptPin::read() {
    return hal->digitalReadSafe(m_Id);
}