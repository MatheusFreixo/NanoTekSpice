/*
** EPITECH PROJECT, 2024
** NanoTekSpice [WSL: Ubuntu]
** File description:
** Pin
*/

#include "./../include/Pin.hpp"


void nts::Pin::setPin(nts::Tristate pin)
{
    _pin = pin;
}

nts::Tristate nts::Pin::getPin()
{
    return _pin;
}

nts::Pin::Pin(const nts::Pin &otherPin)
{
}

nts::Pin::Pin()
{
}

nts::Pin::~Pin()
{
}
