/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <array>
#include <cstddef>
#include <map>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include "interface/IComponent.hpp"
#include "errors/MainError.hpp"
#include "errors/ParserError.hpp"
#include "Factory.hpp"

namespace nts {
    class Parser {
        public:
            class Chipset {
                public:
                    Chipset();
                    Chipset(const Chipset &other);
                    void setComponent(std::string type, std::string name);
                    std::string getType();
                    std::string getName();
                    std::unique_ptr<nts::IComponent> getComponent();
                protected:
                private:
                    std::string _type;
                    std::string _name;
                    std::unique_ptr<nts::IComponent> _component;

            };

            class Link {
                public:
                    void setComponent(std::string firstType, std::string firstPin, std::string secondType, std::string secondPin);
                    std::string getComponentName();
                    std::string getLinkName();
                    std::size_t getComponentPin();
                    std::size_t getLinkPin();

                private:
                    std::string _componentName;
                    std::string _linkName;
                    std::string _componentPin;
                    std::string _linkPin;

            };

            enum Type
            {
                CHIPSET,
                LINK,
                COMMENT
            };
            Parser();
            ~Parser();
            void parsingFile(std::string line);
            void chipsetCase(std::string line);
            void linkCase(std::string line);
            nts::Parser::Type getType();
            std::map<int, nts::Parser::Chipset> getChipset();
            std::map<int, nts::Parser::Link> getLinks();
            std::size_t getchipsetSize();
            std::size_t getlinkSize();
            void checkPin(std::string componentName, std::string componentPin, std::string linkName, std::string linkPin);
            void checkChipset(std::string name);
            void checkFile();
            void checkSection(std::string str);

        protected:
        private:
            nts::Parser::Type _type;
            nts::Parser::Link _link;
            std::size_t _chipsetSize;
            std::size_t _linkSize;
            std::map<int, nts::Parser::Chipset> _chipsetMap;
            std::map<int, nts::Parser::Link> _linkMap;
            bool _checkChipset;
            bool _checkLink;
            const std::set<std::string> _chipsetTypes;
            const std::set<std::string> _specialComponents;
    };
}

#endif /* !PARSER_HPP_ */