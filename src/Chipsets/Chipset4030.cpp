/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Chipset4030
*/

#include "chipsets/Chipset4030.hpp"

void nts::Chipset4030::simulate()
{
    _pin[3]->setPin(_gates.xorGate(_pin[1]->getPin(), _pin[2]->getPin()));
    _pin[4]->setPin(_gates.xorGate(_pin[5]->getPin(), _pin[6]->getPin()));
    _pin[10]->setPin(_gates.xorGate(_pin[8]->getPin(), _pin[9]->getPin()));
    _pin[11]->setPin(_gates.xorGate(_pin[12]->getPin(), _pin[13]->getPin()));
}

nts::Chipset4030::Chipset4030()
{
    for (int i = 1; i <= 13; i++){
        if (i != 7){
            _pin[i] = std::make_shared<Pin>();
            _pin[i]->setPin(nts::Tristate::Undefined);
        }
    }
}

nts::Chipset4030::~Chipset4030()
{
}
