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
public:
    virtual void action(std::list<std::string>, DnaData &) = 0;
    std::string m_message;
    int fromString( std::string s )
    {
        int value;
        std::stringstream ss( s );
        ss >> value;
        return value;
    }
//    virtual void help();
};
#endif //DNA_COMMAND_H
