/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "interface/IComponent.hpp"
#include "errors/FactoryError.hpp"
#include "chipsets/Chipset4081.hpp"
#include "chipsets/Chipset4071.hpp"
#include "chipsets/Chipset4069.hpp"
#include "chipsets/Chipset4030.hpp"
#include "chipsets/Chipset4011.hpp"
#include "chipsets/Chipset4001.hpp"
#include "components/SpecialComponents.hpp"
#include "components/ElementaryComponents.hpp"
#include "components/GatesComponents.hpp"
#include <functional>
#include <memory>
#include <unordered_map>

using componentMap = std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>>;

namespace nts {
    class Factory {
        public:
            Factory();
            ~Factory();
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

        protected:
        private:
            //* Gates Components
            std::unique_ptr<nts::IComponent> create4001() const;
            std::unique_ptr<nts::IComponent> create4011() const;
            std::unique_ptr<nts::IComponent> create4030() const;
            std::unique_ptr<nts::IComponent> create4069() const;
            std::unique_ptr<nts::IComponent> create4071() const;
            std::unique_ptr<nts::IComponent> create4081() const;
            //* Special Components
            std::unique_ptr<nts::IComponent> createInput() const;
            std::unique_ptr<nts::IComponent> createOutput() const;
            std::unique_ptr<nts::IComponent> createTrue() const;
            std::unique_ptr<nts::IComponent> createFalse() const;
            std::unique_ptr<nts::IComponent> createClock() const;
            //* Elementary Components
            std::unique_ptr<nts::IComponent> createAnd() const;
            std::unique_ptr<nts::IComponent> createOr() const;
            std::unique_ptr<nts::IComponent> createXor() const;
            std::unique_ptr<nts::IComponent> createNot() const;
    };
}

#endif /* !FACTORY_HPP_ */
