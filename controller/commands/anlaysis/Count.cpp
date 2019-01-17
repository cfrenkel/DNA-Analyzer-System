//
// Created by cfrenkel on 1/16/19.
//

#include <algorithm>
#include "Count.h"



#include "../../admin/Convert.h"
#include "../../factory/FactoryCommand.h"
#include "../../errorManagment/ERROR_CODES.h"

bool Count::reg = FactoryCommand::registerCommand("count", SharePointer<Command>(new Count));

int countSubString(std::string main, std::string sub)
{
    int occurrences = 0;
    std::string::size_type pos = 0;

    while ((pos = main.find(sub, pos )) != std::string::npos) {
        ++ occurrences;
        pos += sub.length();
//        pos += 1;

    }

    return occurrences;
}

void Count::action(std::list<std::string> args, DnaData & data)
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

    int count = countSubString(main_seq, sub_seq);

    std::stringstream ss;
    ss << count << "\n";
    m_message = ss.str();
}