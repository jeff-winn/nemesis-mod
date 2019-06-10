#ifndef FLYWHEEL_SPEED_COMMAND_H
#define FLYWHEEL_SPEED_COMMAND_H

#include "../FlywheelController.h"
#include "../Command.h"

// Provides a command which handles flywheel speed changes.
class FlywheelSpeedCommand : public Command {
    public:
        FlywheelSpeedCommand(FlywheelController* controller);

        ~FlywheelSpeedCommand() override;

    protected:
        void handleImpl(Packet_t packet) override;
        FlywheelSpeed getSpeedFromPacket(Packet_t packet);
    
    private:
        FlywheelController* m_controller;
};

#endif