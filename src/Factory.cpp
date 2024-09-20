/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Factory
*/

#include "Factory.hpp"

using namespace nts;

//* Gates Components
std::unique_ptr<nts::IComponent> Factory::create4001() const
{
    return std::make_unique<nts::Chipset4001>();
}

std::unique_ptr<nts::IComponent> Factory::create4011() const
{
    return std::make_unique<nts::Chipset4011>();
}

std::unique_ptr<nts::IComponent> Factory::create4030() const
{
    return std::make_unique<nts::Chipset4030>();
}

std::unique_ptr<nts::IComponent> Factory::create4069() const
{
    return std::make_unique<nts::Chipset4069>();
}

std::unique_ptr<nts::IComponent> Factory::create4071() const
{
    return std::make_unique<nts::Chipset4071>();
}

std::unique_ptr<nts::IComponent> Factory::create4081() const
{
    return std::make_unique<nts::Chipset4081>();
}

//* Special Components
std::unique_ptr<nts::IComponent> Factory::createInput() const
{
    return std::make_unique<nts::InputComponent>();
}

std::unique_ptr<nts::IComponent> Factory::createOutput() const
{
    return std::make_unique<nts::OutputComponent>();
}

std::unique_ptr<nts::IComponent> Factory::createTrue() const
{
    return std::make_unique<nts::TrueComponent>();
}

std::unique_ptr<nts::IComponent> Factory::createFalse() const
{
    return std::make_unique<nts::FalseComponent>();
}

std::unique_ptr<nts::IComponent> Factory::createClock() const
{
    return std::make_unique<nts::ClockComponent>();
}

//* Elementary Components
std::unique_ptr<nts::IComponent> Factory::createAnd() const
{
    return std::make_unique<nts::AndComponent>();
}

std::unique_ptr<nts::IComponent> Factory::createOr() const
{
    return std::make_unique<nts::OrComponent>();
}

std::unique_ptr<nts::IComponent> Factory::createXor() const
{
    return std::make_unique<nts::XorComponent>();
}

std::unique_ptr<nts::IComponent> Factory::createNot() const
{
    return std::make_unique<nts::NotComponent>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    const componentMap components = {
        {"output", [this]() { return createOutput(); }},
        {"input", [this]() { return createInput(); }},
        {"true", [this]() { return createTrue(); }},
        {"false", [this]() { return createFalse(); }},
        {"clock", [this]() { return createClock(); }},
        {"and", [this]() { return createAnd(); }},
        {"or", [this]() { return createOr(); }},
        {"xor", [this]() { return createXor(); }},
        {"not", [this]() { return createNot(); }},
        {"4081", [this]() { return create4081(); }},
        {"4071", [this]() { return create4071(); }},
        {"4069", [this]() { return create4069(); }},
        {"4030", [this]() { return create4030(); }},
        {"4011", [this]() { return create4011(); }},
        {"4001", [this]() { return create4001(); }},
    };

    if (components.find(type) != components.end()) {
        return components.at(type)();
    } else {
        throw nts::FactoryError("Wrong type of component");
    }
}

nts::Factory::Factory()
{
}

nts::Factory::~Factory()
{
}
