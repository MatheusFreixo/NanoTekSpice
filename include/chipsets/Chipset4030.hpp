/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Chipset4030
*/

#ifndef CHIPSET4030_HPP_
#define CHIPSET4030_HPP_

#include "AComponent.hpp"
#include "gates/Gates.hpp"

namespace nts {
    class Chipset4030 : public nts::AComponent {
        public:
            Chipset4030();
            ~Chipset4030();
            void simulate() override;

        protected:
        private:
            Gates _gates;

    };
}

#endif /* !CHIPSET4030_HPP_ */
