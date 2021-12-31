#ifndef PUSHER_SPEED_COMMAND_H
#define PUSHER_SPEED_COMMAND_H

#include "../Command.h"
#include "../PusherController.h"

// Provides a command to change the pusher speed.
class PusherSpeedCommand : public Command {
    public:
        PusherSpeedCommand(PusherController* controller);
        ~PusherSpeedCommand() override;

    protected:
        void handleImpl(uint8_t* data, uint16_t len) override;
        PusherSpeed getSpeedFromPacket(uint8_t* data) const;

    private:
        PusherController* m_controller;
};

#endif /* PUSHER_SPEED_COMMAND_H */