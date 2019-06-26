#include "FlywheelTrimAdjustmentCommand.h"
#include "../BitConverter.h"

void FlywheelTrimAdjustmentCommand::handleImpl(Packet_t packet) {
    auto motor = getMotorFromPacket(packet);
    auto adjustment = getAdjustmentFromPacket(packet) / 1024.0F;

    m_controller->setMotorSpeedAdjustment(motor, adjustment);
}

FlywheelMotor FlywheelTrimAdjustmentCommand::getMotorFromPacket(Packet_t packet) {
    auto value = packet.body[0];

    switch (value) {
        case 1: {
            return FlywheelMotor::Motor1;
        }
        case 2: {
            return FlywheelMotor::Motor2;
        }
    }
}

int FlywheelTrimAdjustmentCommand::getAdjustmentFromPacket(Packet_t packet) {
    return Convert.toInt32(packet.body + 1);
}