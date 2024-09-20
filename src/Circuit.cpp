/*
** EPITECH PROJECT, 2024
** NanoTekSpice [WSL: Ubuntu]
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include <cstddef>

void nts::Circuit::usage() {
  std::cout << "USAGE: ./nanotekspice filepath" << std::endl;
  std::cout << "\tfilepath is the path to the file" << std::endl;
}

void nts::Circuit::simulateCommand() {
  _tick++;

  for (size_t i = 0; i < getchipsetSize(); i++) {
    const std::string type = _chipset[i].getType();
    const std::string name = _chipset[i].getName();
    const bool checkComponent = _newComponent.find(name) != _newComponent.end();

    if ((type == "input" || type == "clock") && checkComponent) {
      _inputComponent[name]->setPin(1, _newComponent[name]);

      const std::string inputType = _inputComponent[name]->getType();
      const nts::Tristate pin = _inputComponent[name]->getPin(1);

      if (inputType == "clock" &&
          (_newComponent[name] == nts::Tristate::Null)) {
        if (pin == nts::Tristate::True) {
          _inputComponent[name]->setPin(1, nts::Tristate::False);
        } else if (pin == nts::Tristate::False) {
          _inputComponent[name]->setPin(1, nts::Tristate::True);
        } else if (pin == nts::Tristate::Undefined) {
          _inputComponent[name]->setPin(1, nts::Tristate::Undefined);
        }
      }
      _newComponent[name] = nts::Tristate::Null;
    }
  }
  if (_mainComponent == NULL) {
    for (size_t i = 0; i < getlinkSize(); i++) {
      const std::string linkName = _links[i].getLinkName();
      const std::string componentName = _links[i].getComponentName();
      const size_t componentValue = _links[i].getComponentPin();

      if (_inputComponent.find(componentName) != _inputComponent.end()) {
        _outputComponent[linkName]->setPin(
            1, _inputComponent[componentName]->getPin(componentValue));
        _outputComponent[linkName]->simulate();
      }
    }
    return;
  } else {
    for (size_t i = 0; i < getlinkSize(); i++) {
      const std::string linkName = _links[i].getLinkName();
      const std::string componentName = _links[i].getComponentName();
      const size_t componentValue = _links[i].getComponentPin();
      const size_t linkValue = _links[i].getLinkPin();

      if (_inputComponent.find(componentName) != _inputComponent.end()) {
        _mainComponent->setLink(linkValue, *_inputComponent[componentName],
                                componentValue);
      }
      _mainComponent->simulate();
      if (_outputComponent.find(componentName) != _outputComponent.end()) {
        _outputComponent[componentName]->setPin(
            1, _mainComponent->getPin(linkValue));
      } else if (_outputComponent.find(linkName) != _outputComponent.end()) {
        _outputComponent[linkName]->setPin(
            1, _mainComponent->getPin(componentValue));
      }
    }
  }
}

void nts::Circuit::loopCommand() {
  while (1) {
    simulateCommand();
    displayCommand();
  }
}

int nts::Circuit::setCommand(std::string str) {
  commandMap commands = {{"exit", [this]() { exit(0); }},
                         {"display", [this]() { displayCommand(); }},
                         {"simulate", [this]() { simulateCommand(); }},
                         {"loop", [this]() { loopCommand(); }}};

  if (str.find('=') != std::string::npos) {
    setInputValue(str);
  } else if (commands.find(str) != commands.end()) {
    commands[str]();
  } else {
    throw nts::InputError("Invalid command");
  }

  return 0;
}

void nts::Circuit::displayCommand() {
  std::cout << "tick: " << getTick() << std::endl;
  std::cout << "input(s):" << std::endl;

  for (size_t i = 0; i < getchipsetSize(); i++) {
    std::string type = _chipset[i].getType();
    std::string name = _chipset[i].getName();

    if (_inputTypes.find(type) != _inputTypes.end()) {
      std::cout << "  " << name << ": " << _inputComponent[name]->getPin(1)
                << std::endl;
    }
  }

  std::cout << "output(s):" << std::endl;

  for (size_t i = 0; i < getchipsetSize(); i++) {
    std::string type = _chipset[i].getType();
    std::string name = _chipset[i].getName();

    if (type == "output") {
      std::cout << "  " << name << ": " << _outputComponent[name]->getPin(1)
                << std::endl;
    }
  }
}

void nts::Circuit::setInputValue(std::string str) {
  bool checkName = false;
  std::string namePart = str.substr(0, str.find("="));
  std::string valuePart = str.substr(str.find("=") + 1);
  nts::Tristate value = nts::Tristate::Undefined;

  if (valuePart == "0") {
    value = nts::Tristate::False;
  } else if (valuePart == "1") {
    value = nts::Tristate::True;
  } else if (valuePart == "U") {
    value = nts::Tristate::Undefined;
  } else {
    throw nts::InputError("Invalid value");
  }

  for (size_t i = 0; i < getchipsetSize(); i++) {
    const std::string name = _chipset[i].getName();

    if (name == namePart) {
      _newComponent[name] = value;
      checkName = true;
    }
  }
  if (!checkName) {
    throw nts::InputError("Invalid name");
  }
}

void nts::Circuit::setTick(std::size_t tick) { _tick = tick; }

std::size_t nts::Circuit::getchipsetSize() { return _parser->getchipsetSize(); }

std::size_t nts::Circuit::getlinkSize() { return _parser->getlinkSize(); }

std::size_t nts::Circuit::getTick() { return _tick; }

std::map<int, nts::Parser::Chipset> nts::Circuit::getChipset() {
  return _chipset;
}

std::map<int, nts::Parser::Link> nts::Circuit::getLinks() { return _links; }

void nts::Circuit::setCommand() {}

int nts::Circuit::infiniteLoop() {
  std::string input;
  try {
    setComponent();
  } catch (const nts::FactoryError &e) {
    std::cout << "Catch factory exception in loop: " << e.what() << std::endl;
    return FAILURE;
  }
  simulateCommand();
  _tick = 0;
  while (1) {
    std::cout << "> ";
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      break;
    }
    try {
      if (setCommand(input) == 1) {
        return 0;
      }
    } catch (const nts::InputError &e) {
      std::cout << "Input error: " << e.what() << std::endl;
      return FAILURE;
    }
  }
  return 0;
}

void nts::Circuit::displayComponents() {}

void nts::Circuit::setComponent() {
  nts::Factory factory;

  try {
    for (size_t i = 0; i < getchipsetSize(); i++) {
      std::string type = _chipset[i].getType();
      std::string name = _chipset[i].getName();

      if (_chipsetTypes.find(type) != _chipsetTypes.end()) {
        _mainComponent = factory.createComponent(type);
        _mainComponent->setName(name);
      } else if (_inputTypes.find(type) != _inputTypes.end()) {
        _inputComponent[name] = factory.createComponent(type);
      } else if (type == "output") {
        _outputComponent[name] = factory.createComponent(type);
      }
    }
  } catch (const nts::FactoryError &e) {
    throw nts::FactoryError(e.what());
    return;
  }
  if (_mainComponent != NULL) {
    for (size_t i = 0; i < getlinkSize(); i++) {
      const std::string componentName = _links[i].getComponentName();
      const size_t componentPin = _links[i].getComponentPin();
      const size_t linkPin = _links[i].getLinkPin();

      if (_mainComponent->getName() == componentName) {
        _mainComponent->setLink(componentPin, *_mainComponent, linkPin);
      }
    }
  }
}

int nts::Circuit::setUp(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "please, select a valid file" << std::endl;
    exit(FAILURE);
  }
  std::ifstream inputFile;
  inputFile.open(argv[1]);
  if (inputFile.is_open()) {
    std::string line;
    try {
      while (std::getline(inputFile, line)) {
        _parser->parsingFile(line);
        nts::Parser::Type type = _parser->getType();

        if (type == nts::Parser::Type::CHIPSET &&
            line.compare(0, 10, ".chipsets:") != 0) {
          _parser->chipsetCase(line);
        }
        if (type == nts::Parser::Type::LINK &&
            line.compare(0, 7, ".links:") != 0) {
          _parser->linkCase(line);
        }
      }
    } catch (const nts::ParserError &e) {
      std::cout << "Parser error: " << e.what() << std::endl;
      return FAILURE;
    }
    _chipset = _parser->getChipset();
    _links = _parser->getLinks();
    try {
      _parser->checkFile();
    } catch (const nts::ParserError &e) {
      std::cout << e.what() << std::endl;
      return FAILURE;
    }
  } else {
    std::cout << "The file doesn't exist" << std::endl;
    return FAILURE;
  }
  return 0;
}

nts::Circuit::Circuit()
    : _chipsetTypes({"or", "and", "not", "xor", "4001", "4011", "4030", "4069",
                     "4071", "4081"}),
      _inputTypes({"input", "true", "false", "clock"}) {
  _parser = std::make_shared<nts::Parser>();
  _tick = 0;
  _mainComponent = NULL;
}

nts::Circuit::~Circuit() {}

std::ostream &operator<<(std::ostream &s, nts::Tristate v) {
  if (v == nts::Tristate::True) {
    s << 1;
  } else if (v == nts::Tristate::False) {
    s << 0;
  } else {
    s << 'U';
  }

  return s;
}