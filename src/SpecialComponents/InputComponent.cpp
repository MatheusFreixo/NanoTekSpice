/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** InputComponent
*/

#include "components/SpecialComponents.hpp"

nts::InputComponent::InputComponent()
{
    _pin[1] = std::make_shared<Pin>();
    _pin[1]->setPin(nts::Tristate::Undefined);
    _type = "input";
}

nts::InputComponent::~InputComponent()
{
}
