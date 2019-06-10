#ifndef FLYWHEEL_SPEED_COMMAND_H
#define FLYWHEEL_SPEED_COMMAND_H

#include "FlywheelCommand.h"

// Provides a command which handles flywheel speed changes.
class FlywheelSpeedCommand : public FlywheelCommand {
    public:
        using FlywheelCommand::FlywheelCommand;

    protected:
        void handleImpl(Packet_t packet) override;
        FlywheelSpeed getSpeedFromPacket(Packet_t packet);
};

#endif