#include "Command.h"

void Command::handle(const uint8_t* data, const uint16_t len) {
    if (!validate(data, len)) {
        return;
    }

    handleImpl(data, len);
}

bool Command::validate(const uint8_t* data, const uint16_t len) {
    return true;
}

void Command::handleImpl(const uint8_t* data, const uint16_t len) {
}

bool Command::requiresAuthorization() {
    return true;
}