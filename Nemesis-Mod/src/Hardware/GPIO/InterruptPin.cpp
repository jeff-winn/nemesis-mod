#include "InterruptPin.h"

InterruptPin::InterruptPin(uint8_t id, InterruptCallback onInterruptCallback, InterruptMode mode, Mainboard* mainboard) 
    : Pin(id, mainboard) {
        mainboard->attachInterruptSafe(id, onInterruptCallback, mode, true);
    }

int InterruptPin::read() {
    return hardware->digitalReadSafe(m_Id);
}