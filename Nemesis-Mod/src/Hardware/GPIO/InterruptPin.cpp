#include "InterruptPin.h"

void InterruptPin::init(InterruptCallback onInterruptCallback, InterruptMode mode) {
    hardware->attachInterruptSafe(m_Id, onInterruptCallback, mode, true);
}

int InterruptPin::read() {
    return hardware->digitalReadSafe(m_Id);
}