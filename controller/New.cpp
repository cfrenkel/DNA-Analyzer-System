//
// Created by cfrenkel on 12/27/18.
//

#include "../controller/New.h"
#include "../controller/ERROR_CODES.h"
#include "FactoryCommand.h"

//bool New::reg = FactoryCommand::getInstance()->registerCommand("new", SharePointer<Command>(new New));

void New::action(std::list<std::string> arguments, DnaData & data)
{
    std::string name;
    if (arguments.size() > 2 || arguments.size() < 1)
        throw INVALID_COMMAND;
    if (arguments.size() == 2)
    {
        std::string del = arguments.back().substr(0,1);
            if (del != "@")
            {
                throw INVALID_NAME_SEQ;
            }
        name = arguments.back().substr(1,arguments.back().length());
    }
    else
    {
        std::stringstream ss;
        ss << "seq" << data.getSeqNumber();
        name = ss.str();
    }

    data.newDna(name, arguments.front());
    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getByName(name).getStringDna2() << "\n";
    m_message = ss.str();
}