#ifndef PIN_H
#define PIN_H

#include <stdint.h>
#include "../Interop/HAL.h"

using namespace App::Hardware::Interop;

namespace App { namespace Hardware { namespace GPIO
{
    class Pin {
        public:
            Pin(uint8_t id);

            void setInputMode();
            void setOutputMode();

        protected:
            uint8_t m_Id;
            HAL* hal;
    };
}}}

#endif