#include "BeltSpeedCommand.h"

BeltSpeedCommand::BeltSpeedCommand(FeedController* controller) {
    m_controller = controller;
}

BeltSpeedCommand::~BeltSpeedCommand() {
    m_controller = NULL;
}

void BeltSpeedCommand::handle(Packet_t packet) {
    m_controller->setSpeed(BeltSpeed::Max);
}