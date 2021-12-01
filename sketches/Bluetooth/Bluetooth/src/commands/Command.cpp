#include "Command.h"

Command::~Command() {
}

bool Command::validate() {
    return true;
}

void Command::execute(uint8_t *data, uint8_t len) {
    if (!validate()) {
        return;
    }

    executeImpl(data, len);
}