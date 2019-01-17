//
// Created by cfrenkel on 1/3/19.
//

#include "Len.h"
#include "../../admin/Convert.h"
#include "../../factory/FactoryCommand.h"
#include "../../errorManagment/ERROR_CODES.h"

bool Len::reg = FactoryCommand::registerCommand("len", SharePointer<Command>(new Len));

void Len::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 1)
        throw INVALID_COMMAND;


    int len = data.getDnaByArgs("#" + args.front()).getSharePointerDna()->getLength();

    std::stringstream ss;
    ss << len << "\n";
    m_message = ss.str();
}


std::string Len::help()
{
    std::stringstream ss;
    ss << "Len: **len <seq_id>**\n";
    ss << "returns the length of the DNA sequence by this ID\n\n";

    return ss.str();
}