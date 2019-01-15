//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Rename.h"
#include "../controller/ERROR_CODES.h"
#include "FactoryCommand.h"

bool Rename::reg = FactoryCommand::registerCommand("rename", SharePointer<Command>(new Rename));

void Rename::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 2)
        throw INVALID_COMMAND;

    std::string oldDna = args.front();
    DnaMetaData & metaData = data.getDnaByArgs(oldDna);
    std::string newName = args.back().substr(1, args.back().length());

    metaData.setName(newName);

    std::stringstream ss;
    ss << "[" << metaData.getId() << "] " << newName <<": " << metaData.getSeqStringDna() << "\n";
    m_message = ss.str();
}