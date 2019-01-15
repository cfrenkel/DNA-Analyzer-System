//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Exit.h"
#include "../controller/ERROR_CODES.h"

#include <cstdlib>

#include "FactoryCommand.h"

bool Exit::reg = FactoryCommand::registerCommand("exit", SharePointer<Command>(new Exit));

void Exit::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 0)
        throw INVALID_COMMAND;
    exit(0);
}