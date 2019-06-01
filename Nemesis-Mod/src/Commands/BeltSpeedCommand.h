#ifndef BELT_SPEED_COMMAND_H
#define BELT_SPEED_COMMAND_H

#include "../Controllers/FeedController.h"
#include "Command.h"

// Provides a command to change the belt speed.
class BeltSpeedCommand : public Command {
    public:
        BeltSpeedCommand(FeedController* controller);

        ~BeltSpeedCommand() override;

    protected:
        void handleImpl(Packet_t packet) override;

    private:
        FeedController* m_controller;
};

#endif