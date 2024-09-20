/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** Gates
*/

#include "gates/Gates.hpp"

nts::Tristate nts::Gates::andGate(nts::Tristate a, nts::Tristate b)
{
    if((a == nts::Tristate::True && b == nts::Tristate::True)){
        return nts::Tristate::True;
    } else if (a == nts::Tristate::False || b == nts::Tristate::False){
        return nts::Tristate::False;
    }

    return nts::Tristate::Undefined;
}

nts::Tristate nts::Gates::orGate(nts::Tristate a, nts::Tristate b)
{
    if((a == nts::Tristate::False && b == nts::Tristate::False)){
        return nts::Tristate::False;
    } else if (a == nts::Tristate::True || b == nts::Tristate::True){
        return nts::Tristate::True;
    }

    return nts::Tristate::Undefined;
}

nts::Tristate nts::Gates::notGate(nts::Tristate a)
{
    if(a == nts::Tristate::True){
        return nts::Tristate::False;
    } else if (a == nts::Tristate::Undefined){
        return nts::Tristate::Undefined;
    }

    return nts::Tristate::True;
}

nts::Tristate nts::Gates::xorGate(nts::Tristate a, nts::Tristate b)
{
    if((a == nts::Tristate::False && b == nts::Tristate::False) || (a == nts::Tristate::True && b == nts::Tristate::True)){
        return nts::Tristate::False;
    } else if ((a != b) && ((a != nts::Tristate::Undefined) && (b != nts::Tristate::Undefined))){
        return nts::Tristate::True;
    }

    return nts::Tristate::Undefined;
}

nts::Tristate nts::Gates::norGate(nts::Tristate a, nts::Tristate b)
{
    if((a == nts::Tristate::False && b == nts::Tristate::False)){
        return nts::Tristate::True;
    } else if (a == nts::Tristate::True || b == nts::Tristate::True){
        return nts::Tristate::False;
    }

    return nts::Tristate::Undefined;
}

nts::Tristate nts::Gates::nandGate(nts::Tristate a, nts::Tristate b)
{
    if((a == nts::Tristate::True && b == nts::Tristate::True)){
        return nts::Tristate::False;
    } else if ((a == nts::Tristate::Undefined && b == nts::Tristate::Undefined) ||
                ((a == nts::Tristate::True || b == nts::Tristate::True) && (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined))){
        return nts::Tristate::Undefined;
    }

    return nts::Tristate::True;
}

nts::Gates::Gates()
{
}

nts::Gates::~Gates()
{
}
