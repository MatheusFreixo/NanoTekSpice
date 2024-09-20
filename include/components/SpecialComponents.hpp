/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** SpecialComponents
*/

#ifndef SPECIALCOMPONENTS_HPP_
#define SPECIALCOMPONENTS_HPP_

#include "AComponent.hpp"

namespace nts {
    class InputComponent : virtual public AComponent {
        public:
            InputComponent();
            ~InputComponent();

        protected:
        private:
    };
    class OutputComponent : virtual public AComponent {
        public:
            OutputComponent();
            ~OutputComponent();

        protected:
        private:
    };
    class TrueComponent : virtual public AComponent {
        public:
            TrueComponent();
            ~TrueComponent();

        protected:
        private:
    };
    class FalseComponent : virtual public AComponent {
        public:
            FalseComponent();
            ~FalseComponent();

        protected:
        private:
    };
    class ClockComponent : virtual public AComponent {
        public:
            ClockComponent();
            ~ClockComponent();

        protected:
        private:
    };
}

#endif /* !SPECIALCOMPONENTS_HPP_ */
