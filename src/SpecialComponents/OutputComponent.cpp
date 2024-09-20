/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** OutputComponent
*/

#include "components/SpecialComponents.hpp"


nts::OutputComponent::OutputComponent()
{
    _type = "output";
    _pin[1] = std::make_shared<Pin>();
    _pin[1]->setPin(nts::Tristate::Undefined);
}

nts::OutputComponent::~OutputComponent()
{
}
