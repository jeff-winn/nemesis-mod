#ifndef LOG_H
#define LOG_H

class Logger {
    public:
        // Prints the string.
        void println(const char value[]);

        // Waits for a USB connection to be made to the hardware module.
        void waitForUsbConnection();

    private:
        bool _connected;
};

extern Logger Log;

#endif