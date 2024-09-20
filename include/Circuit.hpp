/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** nanotek
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "file/Parser.hpp"
#include "Factory.hpp"
#include "errors/InputError.hpp"
#include "interface/IComponent.hpp"
#include <iterator>
#include <memory>
#include <string>

#define SUCCESS 0
#define FAILURE 84

using commandMap = std::unordered_map<std::string, std::function<void()>>;

namespace nts {
    typedef struct graph {
        std::unique_ptr<nts::IComponent> *component;
        std::string name;
        std::string type;
        graph *next;
    } graph_s;

    class Circuit {
        public:
            Circuit();
            Circuit(const Circuit &other);
            ~Circuit();
            void setComponent();
            void displayComponents();
            int infiniteLoop();
            void setCommand();
            std::map<int, nts::Parser::Chipset> getChipset();
            std::map<int, nts::Parser::Link> getLinks();
            std::size_t getTick();
            std::size_t getchipsetSize();
            std::size_t getlinkSize();
            void setTick(std::size_t tick);
            void setInputValue(std::string str);
            void displayCommand();
            int setCommand(std::string str);
            void simulateCommand();
            void loopCommand();
            int setUp(int argc, char **argv);
            void usage();

        private:
            std::string _name;
            std::shared_ptr<nts::Parser> _parser;
            std::map<int, nts::Parser::Chipset> _chipset;
            std::map<int, nts::Parser::Link> _links;
            std::size_t _tick;
            std::map<std::string, std::unique_ptr<nts::IComponent>> _componentByName;
            std::map<std::string, std::unique_ptr<nts::IComponent>> _inputComponent;
            std::map<std::string, std::unique_ptr<nts::IComponent>> _outputComponent;
            std::map<std::string, nts::Tristate> _newComponent;
            std::unique_ptr<nts::IComponent> _mainComponent;
            const std::set<std::string> _chipsetTypes;
            const std::set<std::string> _inputTypes;

    };
}

std::ostream &operator<<(std::ostream &s, nts::Tristate v);

#endif /* !NANOTEK_HPP_ */
