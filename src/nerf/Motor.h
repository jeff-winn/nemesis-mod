#include <Arduino.h>

class Motor {
    public:
        void init(uint32_t directionPin, uint32_t pwmPin);

        void start();
        void stop();

    private:
        uint32_t m_directionPin;
        uint32_t m_pwmPin;
};