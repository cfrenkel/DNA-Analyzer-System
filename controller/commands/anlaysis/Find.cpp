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
    std::string sub_seq = args.back();

    if (sub_seq.substr(0,1) == "#" || sub_seq.substr(0,1) == "@")
        sub_seq = data.getDnaByArgs(sub_seq).getSeqStringDnaWithPar(data.getDnaByArgs(sub_seq).getSharePointerDna()->getLength());

    std::transform(sub_seq.begin(), sub_seq.end(),sub_seq.begin(), ::toupper);

    std::stringstream ss;
    ss << main_seq.find(sub_seq) << "\n";
    m_message = ss.str();
}

std::string Find::help()
{
    std::stringstream ss;
    ss << "find: **find <seq_to_find_in> <seq_to_be_found>**\n";
    ss << "returns the (0-based) index of the first appearance of \n";
    ss << "<expressed_sub_seq> in the sequence <seq>. \n\n";

    return ss.str();
}