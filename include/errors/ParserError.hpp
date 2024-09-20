/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ParserError
*/

#ifndef PARSERERROR_HPP_
#define PARSERERROR_HPP_

#include "./MainError.hpp"

namespace nts {
    class ParserError : public nts::MainError {
        public:
            ParserError(std::string str);

        private:
    };
}

#endif /* !PARSERERROR_HPP_ */
