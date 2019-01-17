//
// Created by cfrenkel on 12/29/18.
//

#ifndef DNA_FACTORYCOMMAND_H
#define DNA_FACTORYCOMMAND_H


#include <map>
#include "../commands/Command.h"
#include "../../SharePointer.h"

class FactoryCommand
{
public:

    FactoryCommand();

    Command * getCommand(std::string);

    static bool registerCommand(std::string, SharePointer<Command>);

    static std::map<std::string, SharePointer<Command> > & getMap();
};


#endif //DNA_FACTORYCOMMAND_H
