#ifndef HAL_H
#define HAL_H

namespace App { namespace Hardware { namespace Interop 
{
    enum PinMode {
        Input,
        Output
    };

    enum InterruptMode {
        Rising,
        Falling,
        All
    };

    class HAL {
        public:
            virtual void attachInterruptSafe(uint8_t pin, void (*userFunc)(void), InterruptMode mode);
            
            virtual void digitalWriteSafe(uint8_t pin, uint32_t value);
            virtual int digitalReadSafe(uint8_t pin);

            virtual void pinModeSafe(uint8_t pin, PinMode mode);

            virtual void analogWriteSafe(uint8_t pin, uint32_t value);
            virtual int analogReadSafe(uint8_t pin);

            virtual bool setPwmFrequencySafe(uint8_t pin, uint32_t frequency);
            virtual void pwmWriteSafe(uint8_t pin, uint8_t value);
    };
}}}

#endif