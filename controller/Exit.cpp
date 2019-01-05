//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Exit.h"
#include "../controller/ERROR_CODES.h"

#include <cstdlib>
void Exit::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 0)
        throw INVALID_COMMAND;
    exit(0);
}