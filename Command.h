//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_COMMAND_H
#define DNA_COMMAND_H

#include <string>
#include <list>
#include "DnaData.h"

class Command
{
public:
    virtual void action(std::list<std::string>, DnaData &) = 0;
//    virtual void help();
};
#endif //DNA_COMMAND_H
