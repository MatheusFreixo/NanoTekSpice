/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Chipset4069
*/

#include "chipsets/Chipset4069.hpp"

void nts::Chipset4069::simulate()
{
    _pin[2]->setPin(_gates.notGate(_pin[1]->getPin()));
    _pin[4]->setPin(_gates.notGate(_pin[3]->getPin()));
    _pin[6]->setPin(_gates.notGate(_pin[5]->getPin()));
    _pin[8]->setPin(_gates.notGate(_pin[9]->getPin()));
    _pin[10]->setPin(_gates.notGate(_pin[11]->getPin()));
    _pin[12]->setPin(_gates.notGate(_pin[13]->getPin()));
}

nts::Chipset4069::Chipset4069()
{
    for (int i = 1; i <= 13; i++){
        if (i != 7){
            _pin[i] = std::make_shared<Pin>();
            _pin[i]->setPin(nts::Tristate::Undefined);
        }
    }
}

nts::Chipset4069::~Chipset4069()
{
}
