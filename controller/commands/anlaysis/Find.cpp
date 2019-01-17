//
// Created by cfrenkel on 1/16/19.
//

#include <algorithm>
#include "Find.h"



#include "../../admin/Convert.h"
#include "../../factory/FactoryCommand.h"
#include "../../errorManagment/ERROR_CODES.h"

bool Find::reg = FactoryCommand::registerCommand("find", SharePointer<Command>(new Find));

void Find::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() < 1 || args.size() > 2)
        throw INVALID_COMMAND;

    // > cmd >>> find <seq> <expressed_sub_seq>

    DnaMetaData & dnaMetaData = data.getDnaByArgs(args.front());
    std::string main_seq = dnaMetaData.getSeqStringDnaWithPar(dnaMetaData.getSharePointerDna()->getLength());

    std::transform(args.back().begin(), args.back().end(),args.back().begin(), ::toupper);

    std::stringstream ss;
    ss << main_seq.find(args.back()) << "\n";
    m_message = ss.str();
}