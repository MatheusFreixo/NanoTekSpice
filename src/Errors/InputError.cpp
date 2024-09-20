/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ParserError
*/

#include "errors/InputError.hpp"


nts::InputError::InputError(std::string str) : nts::MainError("Input error: " + str)
{
}
