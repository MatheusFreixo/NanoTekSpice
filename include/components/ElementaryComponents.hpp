/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ElementaryComponents
*/

#ifndef ELEMENTARYCOMPONENTS_HPP_
#define ELEMENTARYCOMPONENTS_HPP_

#include "AComponent.hpp"
#include "gates/Gates.hpp"

namespace nts {
    class AndComponent : virtual public AComponent {
        public:
            AndComponent();
            ~AndComponent();
            nts::Tristate getLink(std::size_t pin) override;
            void simulate() override;

        protected:
        private:
            Gates _gates;
    };
    class OrComponent : virtual public AComponent {
        public:
            OrComponent();
            ~OrComponent();
            void simulate() override;

        protected:
        private:
            Gates _gates;
    };
    class XorComponent : virtual public AComponent {
        public:
            XorComponent();
            ~XorComponent();
            void simulate() override;

        protected:
        private:
            Gates _gates;
    };
    class NotComponent : virtual public AComponent {
        public:
            NotComponent();
            ~NotComponent();
            nts::Tristate compute(std::size_t pin) override;
            void simulate() override;

        protected:
        private:
            Gates _gates;
    };
}

#endif /* !ELEMENTARYCOMPONENTS_HPP_ */
