/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** main
*/

#include "Circuit.hpp"

int main(int argc, char **argv) {
  nts::Circuit circuit;
  if (argc != 2) {
    std::cout << "Invalid number of arguments" << std::endl;
    return FAILURE;
  }

  std::string arg = argv[1];

  if (arg == "-h") {
    circuit.usage();
    return 0;
  }
  if (circuit.setUp(argc, argv) == FAILURE) {
    return FAILURE;
  }
  if (circuit.infiniteLoop() == FAILURE) {
    return FAILURE;
  }
  return 0;
}
