//
// Created by cfrenkel on 12/29/18.
//

#include "FactoryCommand.h"
#include "New.h"
#include "Load.h"
#include "Save.h"
#include "Show.h"


FactoryCommand::FactoryCommand()
{
    commandMap.insert(std::pair<std::string,Command*>("new", new New));
    commandMap.insert(std::pair<std::string,Command*>("load", new Load));
    commandMap.insert(std::pair<std::string,Command*>("save", new Save));
    commandMap.insert(std::pair<std::string,Command*>("show", new Show));
}
Command* FactoryCommand::getCommand(std::string command)
{
    return commandMap.at(command);
}
