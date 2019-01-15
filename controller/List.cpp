//
// Created by cfrenkel on 1/3/19.
//

#include "List.h"
#include "../controller/ERROR_CODES.h"

#include "FactoryCommand.h"

bool List::reg = FactoryCommand::registerCommand("list", SharePointer<Command>(new List));

void List::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 0)
        throw INVALID_COMMAND;
    m_message = data.getAllSeq();
}