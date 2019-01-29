#ifndef HAL_H
#define HAL_H

enum PinMode {
    Input,
    Output
};

class HAL {
    public:
        virtual void digitalWriteSafe(uint8_t pin, uint32_t value);
        virtual int digitalReadSafe(uint8_t pin);

        virtual void pinModeSafe(uint8_t pin, PinMode mode);

        virtual void analogWriteSafe(uint8_t pin, uint32_t value);
        virtual int analogReadSafe(uint8_t pin);
};

#endif