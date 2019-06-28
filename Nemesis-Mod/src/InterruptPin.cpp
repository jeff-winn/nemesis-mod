#include "InterruptPin.h"

InterruptPin::InterruptPin(uint8_t id, InterruptCallback callback, InterruptMode mode, Mainboard* mainboard) : Pin(id, mainboard) {
    m_callback = callback;
    m_mode = mode;
}

int InterruptPin::read() {
    return hardware->digitalReadSafe(m_Id);
}

void InterruptPin::init() {
    hardware->attachInterruptSafe(m_Id, m_callback, m_mode, true);
}