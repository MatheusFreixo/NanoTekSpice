/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <cstddef>
#include <string>

namespace nts {
    enum Tristate {
        Null = -2,
        Undefined = (-true),
        True = true,
        False = false
    };
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate() = 0;
            virtual nts::Tristate compute(std::size_t pin)  = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual nts::Tristate getLink(std::size_t pin) = 0;
            virtual nts::Tristate getPin(std::size_t pin) = 0;
            virtual void setPin(std::size_t pin, nts::Tristate value) = 0;
            virtual std::string getType() = 0;
            virtual std::string getName() = 0;
            virtual void setName(std::string str) = 0;

    };
}


#endif /* !ICOMPONENT_HPP_ */
