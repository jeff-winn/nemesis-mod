#include "Command.h"

Command::~Command() {
}

void Command::handle(Packet_t packet) {
    if (!validate(packet)) {
        return;
    }

    handleImpl(packet);
}

bool Command::validate(Packet_t packet) {
    return true;
}

void Command::handleImpl(Packet_t packet) {
}

bool Command::requiresAuthorization() {
    return true;
}