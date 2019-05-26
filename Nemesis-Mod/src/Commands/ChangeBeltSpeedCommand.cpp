#include "ChangeBeltSpeedCommand.h"

ChangeBeltSpeedCommand::ChangeBeltSpeedCommand(FeedController* controller) {
    m_controller = controller;
}

void ChangeBeltSpeedCommand::handle(Packet_t packet) {
    m_controller->setSpeed(BeltSpeed::High);
}