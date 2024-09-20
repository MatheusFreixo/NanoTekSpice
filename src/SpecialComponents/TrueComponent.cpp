/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** TrueComponent
*/

#include "components/SpecialComponents.hpp"

nts::TrueComponent::TrueComponent()
{
    _pin[1] = std::make_shared<Pin>();
    _pin[1]->setPin(nts::Tristate::True);
    _type = "true";
}

nts::TrueComponent::~TrueComponent()
{
}
