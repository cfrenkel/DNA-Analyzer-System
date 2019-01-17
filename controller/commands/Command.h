//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_COMMAND_H
#define DNA_COMMAND_H

#include <string>
#include <list>
#include "../../model/dnaData/DnaData.h"
#include <sstream>

class Command
{
public:
    virtual void action(std::list<std::string>, DnaData &) = 0;

    virtual std::string help() = 0;

    std::string m_message;

    virtual ~Command(){}
};


#endif //DNA_COMMAND_H
