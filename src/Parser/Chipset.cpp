/*
** EPITECH PROJECT, 2024
** Chipset.cpp
** File description:
** File parser
*/

#include "file/Parser.hpp"

std::unique_ptr<nts::IComponent> nts::Parser::Chipset::getComponent()
{
    return std::move(_component);
}

std::string nts::Parser::Chipset::getName()
{
    return _name;
}

std::string nts::Parser::Chipset::getType()
{
    return _type;
}

void nts::Parser::Chipset::setComponent(std::string type, std::string name)
{
    nts::Factory factory;
    _name = name;
    _type = type;
    _component = factory.createComponent(type);
}

nts::Parser::Chipset::Chipset(const Chipset &other)
{
    nts::Factory factory;
    _name = other._name;
    _type = other._type;
    _component = factory.createComponent(other._type);

}

nts::Parser::Chipset::Chipset()
{
}
