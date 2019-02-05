#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "../Hardware/Motor.h"
#include "../Hardware/Potentiometer.h"

// This frequency seemed to provide the best range of operation from the stock motors.
static const uint32_t MOTOR_FREQUENCY = 35000;

class MotorController {
    public:
        void init(uint8_t pwm, uint8_t pot);

        void start();
        void stop();

    protected:
        virtual Motor* createMotor(uint8_t pwm, int frequency);
        virtual Potentiometer* createPotentiometer(uint8_t pin);

    private:
        Potentiometer* m_potentiometer;
        Motor* m_motor;
};

#endif