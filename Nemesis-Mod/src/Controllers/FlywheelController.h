#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include "../Hardware/Potentiometer.h"
#include "../Hardware/Motor.h"

// This frequency seemed to provide the best range of operation from the stock motors.
static const uint32_t MOTOR_FREQUENCY = 35000;

enum FlywheelMotor {
    Motor1,
    Motor2
};

class FlywheelController {
    public:
        void init(FlywheelMotor flywheel, uint8_t pwm, uint8_t potentiometer);

        void startAll();
        void stopAll();

    protected:
        virtual Motor* createMotor(uint8_t pwm, int frequency);
        virtual Potentiometer* createPotentiometer(uint8_t pin);

    private:
        Potentiometer* m_potentiometer1;
        Motor* m_motor1;

        Potentiometer* m_potentiometer2;
        Motor* m_motor2;
};

#endif