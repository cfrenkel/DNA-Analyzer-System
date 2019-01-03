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

std::string Command::getStringDna(std::string dna)
{
    int length = dna.length();
    std::stringstream ss;
    if (length > 40)
        ss << dna.substr(0,32) << "..." << dna.substr(length-3,length);
    else
        ss << dna;
    return ss.str();
}