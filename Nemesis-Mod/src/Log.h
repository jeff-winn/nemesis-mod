#ifndef LOG_H
#define LOG_H

class Logger {
    public:
        // Prints the value.
        void println(const int value);
        void println(const uint8_t value);
        void println(const char value[]);

        // Waits for a USB connection to be made to the hardware module.
        void waitForUsbConnection();
};

extern Logger Log;

#endif