#ifndef INTERRUPT_SIGNAL_H
#define INTERRUPT_SIGNAL_H

class InterruptSignal {
    public:
        InterruptSignal(uint32_t pin);
        ~InterruptSignal();

        void init();
        
        bool isSet();

    private:
        uint32_t m_pin;
};

#endif /* INTERRUPT_SIGNAL_H */