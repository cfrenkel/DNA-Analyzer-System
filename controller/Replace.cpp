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

std::string getNameReplace(std::string arg, DnaMetaData * d)
{
    std::string parName = arg;
    std::stringstream name;

    if (parName == "@@")
        name << d->getName() << "_r" << d->getId();
    else
    {
        if (parName.substr(0, 1) != "@")
        {
            return "Invalid Argumet :( \n";
        }
        else
            name << parName.substr(1, parName.length());
    }
    return name.str();
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
    args.pop_front();

    SharePointer<ReplaceDecorator> replaceDecor(new ReplaceDecorator(d->getDnaA(), index, new_letter));

    std::stringstream name;
    if (args.size() < 1)
    {
        d->setPtr(replaceDecor);
        name << d->getName();
    }
    else {

        // [24] short_seq_s1_repl_seq_c1_p1: ACGGATCGTA
        name << getNameReplace(args.back(), d);
        data.newDnaByIdna(name.str(), replaceDecor);
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(name.str()) << "] " << name.str() <<": " << data.getByName(name.str()).getStringDna2()<< "\n";
    m_message = ss.str();
}