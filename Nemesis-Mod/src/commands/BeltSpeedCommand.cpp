#include "BeltSpeedCommand.h"

BeltSpeedCommand::BeltSpeedCommand(FeedController* controller) {
    m_controller = controller;
}

BeltSpeedCommand::~BeltSpeedCommand() {
    m_controller = NULL;
}

void BeltSpeedCommand::handleImpl(Packet_t packet) {
    auto newSpeed = getSpeedFromPacket(packet);
    m_controller->setSpeed(newSpeed);
}

BeltSpeed BeltSpeedCommand::getSpeedFromPacket(Packet_t packet) {
    auto value = packet.body[0];

    switch (value) {
        case 1: {
            return BeltSpeed::Normal;
        }
        case 2: {
            return BeltSpeed::High;            
        }
        case 255: {
            return BeltSpeed::Max;
        }
    }
}