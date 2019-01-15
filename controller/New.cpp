//
// Created by cfrenkel on 12/27/18.
//

#include "../controller/New.h"
#include "../controller/ERROR_CODES.h"
#include "FactoryCommand.h"

bool New::reg = FactoryCommand::registerCommand("new", SharePointer<Command>(new New));

void New::action(std::list<std::string> arguments, DnaData & data)
{
    if (arguments.size() > 2 || arguments.size() < 1)
        throw INVALID_COMMAND;

    std::string name;
    std::string seq = arguments.front();

    arguments.pop_front();
    name = data.getNameDnaByArgs(arguments);

    data.newDna(name, seq);

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getByName(name).getSeqStringDna() << "\n";
    m_message = ss.str();
}