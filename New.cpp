//
// Created by cfrenkel on 12/27/18.
//

#include "New.h"

void New::action(std::list<std::string> arguments, DnaData & data)
{
    try {
    data.newDna(arguments.back(), arguments.front());
    }
    catch (const char * mes)
    {
        throw mes;
    }
    std::cout << "[" << data.getIdByName(arguments.back()) << "] " << arguments.back() <<": " << arguments.front() << "\n";
}