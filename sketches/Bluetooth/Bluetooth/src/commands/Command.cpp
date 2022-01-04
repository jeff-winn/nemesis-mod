#include "Command.h"

bool Command::validate() {
    return true;
}

void Command::execute(const uint8_t* data, const uint8_t len) {
    if (!validate()) {
        return;
    }

    executeImpl(data, len);
}