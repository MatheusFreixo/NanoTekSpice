/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Chipset4069
*/

#ifndef CHIPSET4069_HPP_
#define CHIPSET4069_HPP_

#include "AComponent.hpp"
#include "gates/Gates.hpp"

namespace nts {
    class Chipset4069 : public nts::AComponent {
        public:
            Chipset4069();
            ~Chipset4069();
            void simulate() override;

        protected:
        private:
            Gates _gates;
    };
}

#endif /* !CHIPSET4069_HPP_ */
