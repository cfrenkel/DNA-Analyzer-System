//
// Created by cfrenkel on 12/29/18.
//

#include "FactoryCommand.h"
#include "New.h"
#include "Load.h"
#include "Save.h"
#include "Show.h"
#include "Exit.h"
#include "Dup.h"


FactoryCommand::FactoryCommand()
{
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("new", new New));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("load", new Load));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("save", new Save));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("show", new Show));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("exit", new Exit));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("dup", new Dup));
}
Command* FactoryCommand::getCommand(std::string command)
{
    return commandMap.at(command).get();
}
