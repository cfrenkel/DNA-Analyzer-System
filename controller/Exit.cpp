//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Exit.h"

void Exit::action(std::list<std::string> args, DnaData & data)
{
    exit(0);
}