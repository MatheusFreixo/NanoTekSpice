/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ClockComponent
*/

#include "components/SpecialComponents.hpp"

nts::ClockComponent::ClockComponent()
{
    _pin[1] = std::make_shared<Pin>();
    _pin[1]->setPin(nts::Tristate::Undefined);
    _type = "clock";
}

nts::ClockComponent::~ClockComponent()
{
}
