//
// Created by cfrenkel on 1/6/19.
//

#include "../../../model/decorators/ReplaceDecorator.h"
#include "Replace.h"
#include "../../admin/Convert.h"
#include "../../factory/FactoryCommand.h"

// > cmd >>> replace <seq> <index> <new_letter> [: [@<new_seq_name>|@@]]

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
//    if (args.size() > 4)
//    {
//        m_message = "Invalid Argumet :( \n";
//        return;
//    }

    std::string s = args.front(); //pair from
    DnaMetaData & d = data.getDnaByArgs(s);
    args.pop_front();

    SharePointer<ReplaceDecorator> replaceDecor(new ReplaceDecorator(d.getSharePointerDna()));

    int index;
    char new_letter;

    while ( args.size() != 0 && args.front().substr(0, 1) != "@") {
        index = Convert::fromString(args.front());
        args.pop_front();
        new_letter = convertToChar(args.front());
        args.pop_front();

        replaceDecor.get()->addPair(index, new_letter);

    }

    std::string name;
    if (args.size() < 1)
    {
        name = d.getName();
        d.setPtr(replaceDecor);
    }
    else
    {
        // [24] short_seq_s1_repl_seq_c1_p1: ACGGATCGTA
        name = d.getNewSeqName(args, "r");
        data.newDnaByIdna(name, replaceDecor);
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getByNumber(data.getIdByName(name)).getSeqStringDna() << "\n";
    m_message = ss.str();
}

std::string Replace::help()
{
    std::stringstream ss;
    ss << "Replace: ** **\n\n";

    return ss.str();
}