//
// Created by cfrenkel on 1/6/19.
//

#include "../model/ReplaceDecorator.h"
#include "Replace.h"

// > cmd >>> replace <seq> <index> <new_letter> [: [@<new_seq_name>|@@]]

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
    std::string del = s.substr(0, 1);
    DnaMetaData * d;

    if (del == "#")
    {
        int number = fromString(s.substr(1, s.length()));
        d = &(data.getByNumber(number));
    }
    else
    {
        if (del != "@")
        {
            m_message = "Invalid Argumet :( \n";
            return;
        }
        std::string seqName = s.substr(1, s.length());
        d = &(data.getByName(seqName));
    }
    args.pop_front();
    int index = fromString(args.front());
    args.pop_front();
    char new_letter = convertToChar(args.front());

    ReplaceDecorator * replaceDecorator = new ReplaceDecorator(d->getDnaA(), index, new_letter);
    d->setPtr(replaceDecorator);

    std::string parName = args.back();
    std::stringstream name;
    if (parName == "@@")
        name << d->getName() << "_p" << d->getId();
    else
    {
        if (parName.substr(0,1) != "@")
        {
            m_message = "Invalid Argumet :( \n";
            return;
        }
        else
            name << parName.substr(1, parName.length());
    }
    // [24] short_seq_s1_repl_seq_c1_p1: ACGGATCGTA

    d->setName(name.str());
    std::stringstream ss;
    ss << "[" << d->getId() << "] " << name.str() <<": " << d->getStringDna2() << "\n";
    m_message = ss.str();
}