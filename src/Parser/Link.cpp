/*
** EPITECH PROJECT, 2024
** link.cpp
** File description:
** File parser
*/

#include "file/Parser.hpp"

std::size_t nts::Parser::Link::getComponentPin()
{
    return std::stoul(_componentPin);
}

std::size_t nts::Parser::Link::getLinkPin()
{
    return std::stoul(_linkPin);
}

std::string nts::Parser::Link::getComponentName()
{
    return _componentName;
}

std::string nts::Parser::Link::getLinkName()
{
    return _linkName;
}

void nts::Parser::Link::setComponent(std::string firstType, std::string firstPin, std::string secondType, std::string secondPin)
{
    _componentName = firstType;
    _linkName = secondType;
    _componentPin = firstPin;
    _linkPin = secondPin;
}
