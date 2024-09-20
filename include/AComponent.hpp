/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "interface/IComponent.hpp"
#include <exception>
#include <map>
#include <memory>
#include <ostream>
#include <string>
#include "Pin.hpp"

namespace nts {
    class AComponent : virtual public nts::IComponent{
        public:
            AComponent();
            ~AComponent();
            void simulate() override;
            virtual nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate getLink(std::size_t pin) override;
            nts::Tristate getPin(std::size_t pin) override;
            void setPin(std::size_t pin, nts::Tristate value) override;
            std::string getType() override;
            void setName(std::string str) override;
            std::string getName() override;
            class Error : std::exception {
                public:
                    Error();
                    const char *what() const noexcept override;
                    void setMessage(std::string str);

                private:
                    std::string _str;
            };
        protected:
            std::map<std::size_t, std::shared_ptr<Pin>> _pin;
            std::string _type;
            std::string _name;

        private:
    };
}


#endif /* !ACOMPONENT_HPP_ */
