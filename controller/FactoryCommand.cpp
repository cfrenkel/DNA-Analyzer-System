//
// Created by cfrenkel on 12/29/18.
//

#include "../controller/FactoryCommand.h"
#include "../controller/New.h"
#include "../controller/Load.h"
#include "../controller/Save.h"
#include "../controller/Show.h"
#include "../controller/Exit.h"
#include "../controller/Dup.h"
#include "../controller/Rename.h"
#include "../controller/Del.h"
#include "../controller/List.h"
#include "../controller/Pair.h"
#include "../controller/Slice.h"
#include "../controller/Replace.h"
#include "../controller/ERROR_CODES.h"

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

