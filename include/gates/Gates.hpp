/*
** EPITECH PROJECT, 2024
** nanotekspice [WSL: Ubuntu]
** File description:
** Gates
*/

#ifndef GATES_HPP_
#define GATES_HPP_

#include "interface/IComponent.hpp"

namespace nts {
    class Gates {
        public:
            Gates();
            ~Gates();
            nts::Tristate andGate(nts::Tristate a, nts::Tristate b);
            nts::Tristate orGate(nts::Tristate a, nts::Tristate b);
            nts::Tristate notGate(nts::Tristate a);
            nts::Tristate xorGate(nts::Tristate a, nts::Tristate b);
            nts::Tristate norGate(nts::Tristate a, nts::Tristate b);
            nts::Tristate nandGate(nts::Tristate a, nts::Tristate b);

        protected:
        private:
    };

}

#endif /* !GATES_HPP_ */
