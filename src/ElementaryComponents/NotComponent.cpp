/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NotComponent
*/

#include "components/ElementaryComponents.hpp"

void nts::NotComponent::simulate()
{
    _pin[2]->setPin(_gates.notGate(_pin[1]->getPin()));
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (_pin[pin]->getPin() == nts::Tristate::True){
        return nts::Tristate::False;
    } else if (_pin[pin]->getPin() == nts::Tristate::False){
        return nts::Tristate::True;
    }

    return nts::Tristate::Undefined;
}

nts::NotComponent::NotComponent()
{
    for (int i = 1; i <= 2; i++){
        _pin[i] = std::make_shared<Pin>();
        _pin[i]->setPin(nts::Tristate::Undefined);
    }
}

nts::NotComponent::~NotComponent()
{
}
