#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include "MotorController.h"

enum FlywheelMotor {
    Motor1,
    Motor2
};

class FlywheelController {
    public:
        void init(FlywheelMotor flywheel, uint8_t pwm, uint8_t pot);

        void start();
        void stop();

    protected:
        virtual MotorController* createMotorController(uint8_t pwm, uint8_t pot);

    private:
        MotorController* m_motorController1;
        MotorController* m_motorController2;
};

#endif