/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Chipset4081
*/

#ifndef CHIPSET4081_HPP_
#define CHIPSET4081_HPP_

#include "AComponent.hpp"
#include "gates/Gates.hpp"

namespace nts {
    class Chipset4081 : public nts::AComponent {
        public:
            Chipset4081();
            ~Chipset4081();
            void simulate() override;

        protected:
        private:
            Gates _gates;
    };
}

#endif /* !CHIPSET4081_HPP_ */
