/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** MainError
*/

#include "errors/MainError.hpp"

const char *nts::MainError::what() const noexcept
{
    return _str.c_str();
}

nts::MainError::MainError(std::string str)
{
    _str = str;
}
