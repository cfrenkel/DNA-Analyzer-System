//
// Created by cfrenkel on 1/16/19.
//

#include "FindAll.h"

//
// Created by cfrenkel on 1/16/19.
//

#include <algorithm>
#include "FindAll.h"



#include "../../admin/Convert.h"
#include "../../factory/FactoryCommand.h"
#include "../../errorManagment/ERROR_CODES.h"

bool FindAll::reg = FactoryCommand::registerCommand("findall", SharePointer<Command>(new FindAll));

std::string FindAllSubString(std::string main, std::string sub)
{
    int occurrences = 0;
    std::string::size_type pos = 0;
    std::stringstream ss;

    while ((pos = main.find(sub, pos )) != std::string::npos) {
        ss << main.find(sub, pos ) << " ";
        pos += sub.length();
//      pos += 1;

    }
    ss << "\n";
    return ss.str();
}

void FindAll::action(std::list<std::string> args, DnaData & data)
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

    m_message = FindAllSubString(main_seq, sub_seq);
}

std::string FindAll::help()
{
    std::stringstream ss;
    ss << "find: **find all <seq_to_find_in> <seq_to_be_found>**\n";
    ss << "returns the (0-based) indexs of the appearances of \n";
    ss << "<expressed_sub_seq> in the sequence <seq>. \n\n";

    return ss.str();
}