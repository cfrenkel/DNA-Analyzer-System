//
// Created by cfrenkel on 1/3/19.
//

#include "List.h"

void List::action(std::list<std::string> args, DnaData & data)
{
    m_message = data.getAllSeq();
}