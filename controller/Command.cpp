//
// Created by cfrenkel on 1/3/19.
//

#include "Command.h"

int Command::fromString(std::string s)
{
    int value;
    std::stringstream ss( s );
    ss >> value;
    return value;
}

