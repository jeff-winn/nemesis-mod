#ifndef HAL_H
#define HAL_H

// Defines the GPIO pin modes.
enum PinMode {
    // This pin is used for read access.
    Read,
    // This pin is used for write access.
    Write
};

// Defines the interrupt modes for a pin.
enum InterruptMode {
    // Execute the callback on change from off to on only.
    Rising,
    // Execute the callback on change from on to off only.
    Falling,
    // Execute the callback whenever the pin changes.
    All
};

// Provides access to the hardware layer.
class HAL {
    public:
        // Attaches an interrupt pin with a user function callback.
        virtual void attachInterruptSafe(uint8_t pin, void (*userFunc)(void), InterruptMode mode);
        
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