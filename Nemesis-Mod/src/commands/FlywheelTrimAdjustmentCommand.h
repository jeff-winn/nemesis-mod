#ifndef FLYWHEEL_TRIM_ADJUSTMENT_COMMAND_H
#define FLYWHEEL_TRIM_ADJUSTMENT_COMMAND_H

#include "../Command.h"
#include "FlywheelCommand.h"

// Provides a command which handles flywheel trim adjustment changes.
class FlywheelTrimAdjustmentCommand : public FlywheelCommand {
    public:
        using FlywheelCommand::FlywheelCommand;

    protected:
        void handleImpl(Packet_t packet) override;

        FlywheelMotor getMotorFromPacket(Packet_t packet);
        byte getAdjustmentFromPacket(Packet_t packet);        
};

#endif