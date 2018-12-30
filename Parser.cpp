//
// Created by cfrenkel on 12/27/18.
//

#include <sstream>
#include "Parser.h"

std::list<std::string> Parser::parse(std::string c)
{
    char delimiter = ' ';
    std::list<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(c);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}