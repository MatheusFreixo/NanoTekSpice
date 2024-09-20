/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** InputError
*/

#ifndef INPUTERROR_HPP_
#define INPUTERROR_HPP_

#include "./MainError.hpp"

namespace nts {
    class InputError : public nts::MainError {
        public:
            InputError(std::string str);

        private:
    };
}

#endif /* !INPUTERROR_HPP_ */
