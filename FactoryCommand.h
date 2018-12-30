//
// Created by cfrenkel on 12/29/18.
//

#ifndef DNA_FACTORYCOMMAND_H
#define DNA_FACTORYCOMMAND_H


#include <map>
#include "Command.h"

class FactoryCommand
{
public:
    FactoryCommand();
    Command * getCommand(std::string);
private:
    std::map<std::string, Command*> commandMap;
};


#endif //DNA_FACTORYCOMMAND_H
