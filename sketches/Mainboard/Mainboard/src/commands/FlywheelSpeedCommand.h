#ifndef FLYWHEEL_SPEED_COMMAND_H
#define FLYWHEEL_SPEED_COMMAND_H

#include "FlywheelCommand.h"

// Provides a command which handles flywheel speed changes.
class FlywheelSpeedCommand : public FlywheelCommand {
    public:
        using FlywheelCommand::FlywheelCommand;

    protected:
        void handleImpl(const uint8_t* data, const uint16_t len) override;
        FlywheelSpeed getSpeedFromPacket(const uint8_t* data) const;
};

#endif /* FLYWHEEL_SPEED_COMMAND_H */