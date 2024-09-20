/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Chipset4011
*/

#ifndef CHIPSET4011_HPP_
#define CHIPSET4011_HPP_

#include "AComponent.hpp"
#include "gates/Gates.hpp"

namespace nts {
    class Chipset4011 : public nts::AComponent {
        public:
            Chipset4011();
            ~Chipset4011();
            void simulate() override;

        protected:
        private:
            Gates _gates;
    };
}

#endif /* !CHIPSET4011_HPP_ */
