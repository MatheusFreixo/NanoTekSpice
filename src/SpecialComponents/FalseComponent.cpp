/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FalseComponent
*/

#include "components/SpecialComponents.hpp"

nts::FalseComponent::FalseComponent()
{
    _pin[1] = std::make_shared<Pin>();
    _pin[1]->setPin(nts::Tristate::False);
    _type = "false";
}

nts::FalseComponent::~FalseComponent()
{
}
