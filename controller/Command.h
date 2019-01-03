//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_COMMAND_H
#define DNA_COMMAND_H

#include <string>
#include <list>
#include "../model/DnaData.h"
#include <sstream>

class Command
{
protected:
    static bool m_register;
public:
    virtual void action(std::list<std::string>, DnaData &) = 0;
    std::string m_message;
    int fromString( std::string s );
    std::string getStringDna(std::string dna);
//    virtual void help();
};

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
#endif //DNA_COMMAND_H
