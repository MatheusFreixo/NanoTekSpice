/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** OrComponent
*/

#include "components/ElementaryComponents.hpp"

void nts::OrComponent::simulate()
{
    _pin[3]->setPin(_gates.orGate(_pin[1]->getPin(), _pin[2]->getPin()));
}

nts::OrComponent::OrComponent()
{
    for (int i = 1; i <= 3; i++){
        _pin[i] = std::make_shared<Pin>();
        _pin[i]->setPin(nts::Tristate::Undefined);
    }
    _type = "or";
}

nts::OrComponent::~OrComponent()
{
}

