#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include "Potentiometer.h"
#include "Motor.h"

enum FlywheelMotor {
    Motor1,
    Motor2
};

class FlywheelController {
    public:
        void init(FlywheelMotor flywheel, uint8_t pwm, uint8_t potentiometer);

        void startAll();
        void stopAll();

    private:
        Potentiometer* m_potentiometer1;
        Motor* m_motor1;

        Potentiometer* m_potentiometer2;
        Motor* m_motor2;
};

#endif