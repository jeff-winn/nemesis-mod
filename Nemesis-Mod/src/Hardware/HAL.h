#ifndef HAL_H
#define HAL_H

enum PinMode {
    Input,
    Output
};

class HAL {
    public:
        void digitalWriteSafe(uint8_t pin, uint32_t value);
        int digitalReadSafe(uint8_t pin);
};

#endif