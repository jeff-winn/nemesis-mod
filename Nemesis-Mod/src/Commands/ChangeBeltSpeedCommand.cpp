#include "ChangeBeltSpeedCommand.h"

ChangeBeltSpeedCommand::ChangeBeltSpeedCommand(FeedController* controller) {
    m_controller = controller;
}

void ChangeBeltSpeedCommand::handle(Packet_t packet) {
    auto speed = (BeltSpeed)packet.body[0];
    Serial.println((byte)speed);

    m_controller->setSpeed(speed);
}