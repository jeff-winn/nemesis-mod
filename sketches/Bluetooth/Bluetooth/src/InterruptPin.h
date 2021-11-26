#ifndef INTERRUPT_PIN_H
#define INTERRUPT_PIN_H

class InterruptPin {
    public:
        InterruptPin();

        void init();
        
        void set();

        void reset();
};

#endif /* INTERRUPT_PIN_H */