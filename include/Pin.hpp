/*
** EPITECH PROJECT, 2024
** NanoTekSpice [WSL: Ubuntu]
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "interface/IComponent.hpp"

namespace nts {
    class Pin {
        public:
            Pin();
            Pin(const nts::Pin &otherPin);
            ~Pin();
            void setPin(nts::Tristate pin);
            nts::Tristate getPin();

        protected:
            nts::Tristate _pin;
        private:
    };

}

#endif /* !PIN_HPP_ */
