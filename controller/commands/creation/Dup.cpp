//
// Created by cfrenkel on 12/30/18.
//

#include "Dup.h"
#include "../../errorManagment/ERROR_CODES.h"
#include "../../factory/FactoryCommand.h"

bool Dup::reg = FactoryCommand::registerCommand("dup", SharePointer<Command>(new Dup));

void Dup::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 2 || args.size() < 1)
        throw INVALID_COMMAND;

    DnaMetaData & metaData = data.getDnaByArgs(args.front());
    args.pop_front();
    std::string name = metaData.getNewSeqName(args, "");
    data.newDnaByDna(name, metaData);

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getByName(name).getSeqStringDna() << "\n";
    m_message = ss.str();
}


std::string Dup::help()
{
    std::stringstream ss;
    ss << "Dup: ** **\n\n";

    return ss.str();
}