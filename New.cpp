//
// Created by cfrenkel on 12/27/18.
//

#include "New.h"

void New::action(std::list<std::string> arguments, DnaData & data)
{
    std::string del = arguments.back().substr(0,1);
    std::string arg = arguments.back().substr(1,arguments.back().length());
    try {
        if (del == "#")
        {

        }
        else
        {
            data.newDna(arg, arguments.front());
        }
    }
    catch (const char * mes)
    {
        throw mes;
    }
    std::stringstream ss;
    int id = data.getIdByName(arg);
    ss << "[" << data.getIdByName(arg) << "] " << arg <<": " << arguments.front() << "\n";
    m_message = ss.str();
}