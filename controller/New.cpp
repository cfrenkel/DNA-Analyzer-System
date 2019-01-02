//
// Created by cfrenkel on 12/27/18.
//

#include "../controller/New.h"

void New::action(std::list<std::string> arguments, DnaData & data)
{
    std::string name;
    if (arguments.size() > 1)
    {
        std::string del = arguments.back().substr(0,1);
            if (del != "@")
            {
                throw "Invalid Name Of Sequence\n";
            }
        name = arguments.back().substr(1,arguments.back().length());
    }
    else
    {
        std::stringstream ss;
        ss << "seq" << data.getSeqNumber();
        name = ss.str();
    }
    try
    {
       data.newDna(name, arguments.front());
    }

    catch (const char * mes)
    {
        throw mes;
    }
    std::stringstream ss;
    int id = data.getIdByName(name);
    ss << "[" << data.getIdByName(name) << "] " << name <<": ";
    int length = arguments.front().length();
    if (length > 40)
        ss << arguments.front().substr(0,32) << "..." << arguments.front().substr(length-3,length) << "\n";
    else
        ss << arguments.front() << "\n";
    m_message = ss.str();
}