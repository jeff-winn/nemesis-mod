#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include "Motor.h"

class FlywheelController {
    public:
        void init(uint32_t in1, uint32_t in2, uint32_t in3, uint32_t in4);

        void setDirection(MotorDirection direction);
        void startAll();
        void stopAll();

    private:
        Motor* m_motor1;
        Motor* m_motor2;
};

#endif