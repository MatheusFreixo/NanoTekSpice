/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** MainError
*/

#ifndef MAINERROR_HPP_
#define MAINERROR_HPP_

#include <string>

namespace nts {
    class MainError : std::exception{
        public:
            MainError(std::string str);
            virtual const char *what() const noexcept override;

        protected:
        private:
            std::string _str;

    };

}

#endif /* !MAINERROR_HPP_ */
