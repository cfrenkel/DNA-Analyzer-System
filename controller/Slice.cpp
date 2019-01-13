//
// Created by cfrenkel on 1/2/19.
//

#include "../model/SliceDecorator.h"
#include "Slice.h"

std::string getNameSlice(std::string arg, DnaMetaData * d)
{
    std::string parName = arg;
    std::stringstream name;

    if (parName == "@@")
        name << d->getName() << "_s" << d->getId();
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

void Slice::action(std::list<std::string> args, DnaData & data)
{
    //slice <seq> <from_ind> <to_ind> [: [@<new_seq_name>|@@]]

    if (args.size() < 3 || args.size() > 4)
       m_message = "Invalid Argument :(\n";
    std::string s = args.front();
    std::string del = s.substr(0, 1);

    DnaMetaData * d;

    if (del == "#") {
        d = &(data.getByNumber(fromString(s.substr(1, s.length()))));
    }
    else
    {
        d = &(data.getByName(s.substr(1, s.length())));
    }
    args.pop_front();
    int from = fromString(args.front());
    args.pop_front();
    int to = fromString(args.front());
    args.pop_front();
    std::stringstream name;
    SharePointer<SliceDecorator> sliceDecor(new SliceDecorator(d->getDnaA(), from, to, to-from));

    if (args.size() < 1) {
        d->setPtr(sliceDecor);
        name << d->getName();
    }
    else
    {
        name << getNameSlice(args.back(), d);
        data.newDnaByIdna(name.str(), sliceDecor);
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(name.str()) << "] " << name.str() <<": " << data.getByName(name.str()).getStringDna2()<< "\n";
    m_message = ss.str();

}