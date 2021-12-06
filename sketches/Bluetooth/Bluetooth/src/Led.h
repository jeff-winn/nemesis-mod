#ifndef LED_H
#define LED_H

class Led {
    public:
        Led();
        ~Led();

        void init();

        void on();

        void off();
};

#endif /* LED_H */