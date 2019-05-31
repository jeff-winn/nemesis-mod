#include "BeltSpeedCommand.h"

BeltSpeedCommand::BeltSpeedCommand(FeedController* controller) {
    m_controller = controller;
}

void BeltSpeedCommand::handle(Packet_t packet) {
    m_controller->setSpeed(BeltSpeed::High);
}