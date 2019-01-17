//
// Created by cfrenkel on 12/29/18.
//

#include "FactoryCommand.h"

#include "../errorManagment/ERROR_CODES.h"

FactoryCommand::FactoryCommand() {}

std::map<std::string, SharePointer<Command> > & FactoryCommand::getMap()
{
    static std::map<std::string,SharePointer<Command> > commandMap;
    return commandMap;
}

Command * FactoryCommand::getCommand(std::string command)
{
    if (FactoryCommand::getMap().find(command) == FactoryCommand::getMap().end())
    {
        throw NOT_FOUND_COAMMAND;
    }
    return FactoryCommand::getMap()[command].get();
}

bool FactoryCommand::registerCommand(std::string command, SharePointer<Command> sp)
{
    FactoryCommand::getMap().insert(std::pair<std::string,SharePointer<Command> >(command, sp));
    return true;
}

