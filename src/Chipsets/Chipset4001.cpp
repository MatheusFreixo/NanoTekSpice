/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Chipset4001
*/

#include "chipsets/Chipset4001.hpp"

void nts::Chipset4001::simulate()
{
    _pin[3]->setPin(_gates.norGate(_pin[1]->getPin(), _pin[2]->getPin()));
    _pin[4]->setPin(_gates.norGate(_pin[5]->getPin(), _pin[6]->getPin()));
    _pin[10]->setPin(_gates.norGate(_pin[8]->getPin(), _pin[9]->getPin()));
    _pin[11]->setPin(_gates.norGate(_pin[12]->getPin(), _pin[13]->getPin()));
}

nts::Chipset4001::Chipset4001()
{
    for (int i = 1; i <= 13; i++){
        if (i != 7){
            _pin[i] = std::make_shared<Pin>();
            _pin[i]->setPin(nts::Tristate::Undefined);
        }
    }
}

nts::Chipset4001::~Chipset4001()
{
}
