/*
** EPITECH PROJECT, 2024
** Parser.cpp
** File description:
** File parser
*/

#include "file/Parser.hpp"

nts::Parser::Parser() : _chipsetTypes({
                                            "input", "output", "or", "and", "true", "false", 
                                            "not", "xor", "4001", "4011", "4030", "4069", 
                                            "4071", "4081", "clock"
                                        }),
                        _specialComponents({
                                            "input", "output", "true", "false", "clock"
                                        })
{
    _chipsetSize = 0;
    _linkSize = 0;
    _checkChipset = false;
    _checkLink = false;
}

nts::Parser::~Parser()
{
}

void nts::Parser::checkChipset(std::string name)
{
    for (size_t i = 0; i < _chipsetSize; i++){
        if (_chipsetMap[i].getName() == name){
            throw nts::ParserError("More than one component with the same name");
        }
    }
}

void nts::Parser::chipsetCase(std::string line)
{
    if (line.find(" ") == std::string::npos){
        throw nts::ParserError(".chipset section is in the wrong format");
    }

    const std::string typePart = line.substr(0, line.find(" "));
    const std::string namePart = line.substr(line.find(" ")+1);

    if (typePart.empty() || namePart.empty()){
        throw nts::ParserError("Type or name of the component missing");
    }

    if (_chipsetTypes.find(typePart) != _chipsetTypes.end()){
        checkChipset(namePart);
        _chipsetMap[_chipsetSize].setComponent(typePart, namePart);
        _chipsetSize++;
    } else {
        throw nts::ParserError("(Chipset) Unknow component's type named " + namePart);
    }
}

void nts::Parser::checkPin(std::string componentName, std::string componentPin, std::string linkName, std::string linkPin)
{
    for (size_t i = 0; i < _chipsetSize; i++){
        const std::string type = _chipsetMap[i].getType();
        const bool checkComponent = _specialComponents.find(type) != _specialComponents.end();

        if (_chipsetMap[i].getName() == componentName && checkComponent){
            if (std::stoi(componentPin) <= 0 || std::stoi(componentPin) > 1){
                throw ParserError("Invalid component pin");
            }
        }
        if (_chipsetMap[i].getName() == linkName && checkComponent){
            if (std::stoi(linkPin) <= 0 || std::stoi(linkPin) >= 14){
                throw ParserError("Invalid link pin");
            }
        }
    }
    if (std::stoi(componentPin) <= 0 || std::stoi(componentPin) >= 14){
        throw ParserError("Invalid component pin");
    }
    if (std::stoi(linkPin) <= 0 || std::stoi(linkPin) >= 14){
        throw ParserError("Invalid link pin");
    }
}

void nts::Parser::linkCase(std::string line)
{
    bool checkComponent = false;
    bool checkLink = false;

    if (line.find(" ") == std::string::npos){
        throw nts::ParserError(".link section is in the wrong format");
    }

    const std::string componentPart = line.substr(0, line.find(" "));
    const std::string linkPart = line.substr(line.find(" ") + 1);

    if (componentPart.find(":") == std::string::npos
    || linkPart.find(":") == std::string::npos){
        throw nts::ParserError(".link section is in the wrong format");
    }

    const std::array<std::string, 4> linksArray = {
        componentPart.substr(0, componentPart.find(":")),
        componentPart.substr(componentPart.find(":") + 1),
        linkPart.substr(0, linkPart.find(":")),
        linkPart.substr(linkPart.find(":") + 1)
    };

    for (size_t i = 0; i <= 3; i++){
        if (linksArray[i].empty()){
            throw nts::ParserError("Pin or name empty");
        }
    }

    for (size_t i = 0; i < _chipsetSize; i++) {
        const std::string name = _chipsetMap[i].getName();

        if (linksArray[0] == name) {
            checkComponent = true;
        }
        if (linksArray[2] == name) {
            checkLink = true;
        }
    }
    if (checkComponent == false || checkLink == false) {
        throw nts::ParserError("Unknow component named " + linksArray[0]);
    }

    checkPin(linksArray[0], linksArray[1], linksArray[2], linksArray[3]);

    _link.setComponent(linksArray[0], linksArray[1], linksArray[2], linksArray[3]);
    _linkMap[_linkSize] = _link;
    _linkSize++;
}

void nts::Parser::checkFile()
{
    if (!_checkChipset || !_checkLink) {
        throw nts::ParserError(".chipset or .link missing");
    }
    for (size_t i = 0, j = 0; i < _chipsetSize; j++){
        const std::string name = _chipsetMap[i].getName();

        if (j == _linkSize){
            throw nts::ParserError("Some components are not in the link section");
        }
        if (name == _linkMap[j].getLinkName() || name == _linkMap[j].getComponentName()){
            i++;
            j = -1;
        }
    }
}

void nts::Parser::checkSection(std::string str)
{
    if (str.compare(0, 10, ".chipsets:") == 0 && _checkChipset){
        throw nts::ParserError("More than one chipset section");
    }
    if (str.compare(0, 7, ".links:") == 0 && _checkLink){
        throw nts::ParserError("More than one link section");
    }
}

void nts::Parser::parsingFile(std::string line)
{
    checkSection(line);
    if (line.compare(0, 10, ".chipsets:") == 0) {
        _checkChipset = true;
        _type = nts::Parser::Type::CHIPSET;
    } else if (line.compare(0, 7, ".links:") == 0) {
        _checkLink = true;
        _type = nts::Parser::Type::LINK;
    } else if(line[0] == '#' || line.empty()) {
         _type = nts::Parser::Type::COMMENT;
    } else if (line.find('#') != std::string::npos) {
        line.resize(line.find("#"));
    }
}

nts::Parser::Type nts::Parser::getType()
{
    return _type;
}


std::map<int, nts::Parser::Chipset> nts::Parser::getChipset()
{
    return _chipsetMap;
}

std::map<int, nts::Parser::Link> nts::Parser::getLinks()
{
    return _linkMap;
}

std::size_t nts::Parser::getchipsetSize()
{
    return _chipsetSize;
}

std::size_t nts::Parser::getlinkSize()
{
    return _linkSize;
}
