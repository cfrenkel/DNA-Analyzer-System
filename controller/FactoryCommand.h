//
// Created by cfrenkel on 12/29/18.
//

#ifndef DNA_FACTORYCOMMAND_H
#define DNA_FACTORYCOMMAND_H


#include <map>
#include "../controller/Command.h"
#include "../SharePointer.h"

class FactoryCommand
{
public:
    FactoryCommand();
    Command * getCommand(std::string);
//    bool registerCommand(std::string, SharePointer<Command>);
//
//    static SharePointer<FactoryCommand> getInstance();
//    static SharePointer<FactoryCommand> m_instance;

private:
    std::map<std::string, SharePointer<Command> > commandMap;
};


#endif //DNA_FACTORYCOMMAND_H
