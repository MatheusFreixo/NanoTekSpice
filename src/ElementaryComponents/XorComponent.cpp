/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** XorComponent
*/

#include "components/ElementaryComponents.hpp"

void nts::XorComponent::simulate()
{
    _pin[3]->setPin(_gates.xorGate(_pin[1]->getPin(), _pin[2]->getPin()));
}

nts::XorComponent::XorComponent()
{
    for (int i = 1; i <= 3; i++){
        _pin[i] = std::make_shared<Pin>();
        _pin[i]->setPin(nts::Tristate::Undefined);
    }
}

nts::XorComponent::~XorComponent()
{
}
