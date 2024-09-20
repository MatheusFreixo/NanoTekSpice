/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AndComponent
*/

#include "components/ElementaryComponents.hpp"

void nts::AndComponent::simulate()
{
    _pin[3]->setPin(_gates.andGate(_pin[1]->getPin(), _pin[2]->getPin()));
}

nts::Tristate nts::AndComponent::getLink(std::size_t pin)
{
    return compute(pin);
}

nts::AndComponent::AndComponent()
{
    for (int i = 1; i <= 3; i++){
        _pin[i] = std::make_shared<Pin>();
        _pin[i]->setPin(nts::Tristate::Undefined);
    }
}

nts::AndComponent::~AndComponent()
{
}
