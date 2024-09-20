/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Chipset4071
*/

#ifndef CHIPSET4071_HPP_
#define CHIPSET4071_HPP_

#include "AComponent.hpp"
#include "gates/Gates.hpp"

namespace nts {
    class Chipset4071 : public nts::AComponent {
        public:
            Chipset4071();
            ~Chipset4071();
            void simulate() override;

        protected:
        private:
            Gates _gates;
    };
}

#endif /* !CHIPSET4071_HPP_ */
