/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FactoryError
*/

#ifndef FACTORYERROR_HPP_
#define FACTORYERROR_HPP_

#include "./MainError.hpp"

namespace nts {
    class FactoryError : public nts::MainError {
        public:
            FactoryError(std::string str);

        protected:
        private:
    };

}

#endif /* !FACTORYERROR_HPP_ */
