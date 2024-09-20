/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** FactoryError
*/

#include "errors/FactoryError.hpp"

nts::FactoryError::FactoryError(std::string str) : nts::MainError("Factory error: " + str)
{
}
