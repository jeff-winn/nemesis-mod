#ifndef MAINBOARD_H
#define MAINBOARD_H

// Defines the GPIO pin modes.
enum class PinMode {
    // This pin is used for read access.
    Read,
    // This pin is used for write access.
    Write
};

// Provides a wrapper for hardware control of the mainboard.
class Mainboard {
    public:
        // Delays the execution for the time (in milliseconds) specified.
        virtual void delaySafe(unsigned long milliseconds);
        
        // Writes the value to the digital pin specified.
        virtual void digitalWriteSafe(uint8_t pin, uint32_t value);

        // Reads the value of the digital pin specified.
        virtual int digitalReadSafe(uint8_t pin);

        // Sets the mode for the pin specified.
        virtual void pinModeSafe(uint8_t pin, PinMode mode);

        // Writes the value to the analog pin specified.
        virtual void analogWriteSafe(uint8_t pin, uint32_t value);

        // Reads the value of the analog pin specified.
        virtual int analogReadSafe(uint8_t pin);
};

#endif