/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ParserError
*/

#include "errors/ParserError.hpp"


nts::ParserError::ParserError(std::string str) : nts::MainError("Parser error: " + str)
{
}
