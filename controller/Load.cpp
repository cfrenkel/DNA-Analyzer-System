//
// Created by cfrenkel on 12/29/18.
//

#include "../controller/Load.h"
#include "../model/DNAReader.h"
#include "../controller/ERROR_CODES.h"
#include "FactoryCommand.h"

bool Load::reg = FactoryCommand::registerCommand("load", SharePointer<Command>(new Load));

void Load::action(std::list<std::string> args, DnaData &data)
{
    if (args.size() > 2 || args.size() < 1)
        throw INVALID_COMMAND;

    DNAReader reader(args.front());
    args.pop_front();
    std::string name = data.getNameDnaByArgs(args);
    data.newDna(name, reader.read());

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " <<name<<": " << data.getByName(name).getSeqStringDna() << "\n";
    m_message = ss.str();
    //    data.printNameMap();
    //    data.printIdMap();
}