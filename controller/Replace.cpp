//
// Created by cfrenkel on 1/6/19.
//

#include "../model/ReplaceDecorator.h"
#include "../controller/Replace.h"
#include "../controller/Convert.h"

// > cmd >>> replace <seq> <index> <new_letter> [: [@<new_seq_name>|@@]]
#include "FactoryCommand.h"

bool Replace::reg = FactoryCommand::registerCommand("replace", SharePointer<Command>(new Replace));

char convertToChar(std::string c)
{
        if (c == "C" )
            return 'C';
        if (c == "A" )
            return 'A';
        if (c == "T" )
            return 'T';
        if (c == "G" )
            return 'G';
    return '0';
}

void Replace::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 4)
    {
        m_message = "Invalid Argumet :( \n";
        return;
    }

    std::string s = args.front(); //pair from
    DnaMetaData & d = data.getDnaByArgs(s);

    args.pop_front();
    int index = Convert::fromString(args.front());
    args.pop_front();
    char new_letter = convertToChar(args.front());
    args.pop_front();

    SharePointer<ReplaceDecorator> replaceDecor(new ReplaceDecorator(d.getSharePointerDna(), index, new_letter));

    std::string name;
    if (args.size() < 1)
    {
        d.setPtr(replaceDecor);
    }
    else
    {
        // [24] short_seq_s1_repl_seq_c1_p1: ACGGATCGTA
        name = d.getNewSeqName(args, "r");
        data.newDnaByIdna(name, replaceDecor);
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getByName(name).getSeqStringDna() << "\n";
    m_message = ss.str();
}