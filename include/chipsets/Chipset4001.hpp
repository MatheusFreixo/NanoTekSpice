/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Chipset4001
*/

#ifndef CHIPSET4001_HPP_
#define CHIPSET4001_HPP_

#include "AComponent.hpp"
#include "gates/Gates.hpp"

namespace nts {
    class Chipset4001 : public nts::AComponent {
        public:
            Chipset4001();
            ~Chipset4001();
            void simulate() override;

        protected:
        private:
            Gates _gates;
    };
}

#endif /* !CHIPSET4001_HPP_ */
