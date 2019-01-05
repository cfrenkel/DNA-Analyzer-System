//
// Created by cfrenkel on 1/3/19.
//

#include "List.h"
#include "../controller/ERROR_CODES.h"

void List::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 0)
        throw INVALID_COMMAND;
    m_message = data.getAllSeq();
}