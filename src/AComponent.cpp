/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"

std::string nts::AComponent::getName()
{
    return _name;
}

void nts::AComponent::setName(std::string str)
{
    _name = str;
}

std::string nts::AComponent::getType()
{
    return _type;
}

void nts::AComponent::setPin(std::size_t Pin, nts::Tristate value)
{
    if ((value != nts::Tristate::Null) && (_pin.find(Pin) != _pin.end())){
        _pin[Pin]->setPin(value);
    }
}

void nts::AComponent::simulate()
{
}

nts::Tristate nts::AComponent::getLink(std::size_t pin)
{
    return compute(pin);
}

nts::Tristate nts::AComponent::getPin(std::size_t pin)
{
    return _pin[pin]->getPin();
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    return _pin[pin]->getPin();
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (_type == other.getType()){
        _pin[pin] = _pin[otherPin];
    } else {
        _pin[pin]->setPin(other.getPin(otherPin));
    }

}

nts::AComponent::AComponent()
{
}

nts::AComponent::~AComponent()
{
}
