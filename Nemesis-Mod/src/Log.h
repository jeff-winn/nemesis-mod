#ifndef LOG_H
#define LOG_H

class Logger {
    public:
        void println(const char value[]);

        void waitForUsbConnection();

    private:
        bool _connected;
};

extern Logger Log;

#endif