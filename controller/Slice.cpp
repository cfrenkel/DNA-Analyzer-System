//
// Created by cfrenkel on 1/2/19.
//

#include "../model/SliceDecorator.h"
#include "Slice.h"

void Slice::action(std::list<std::string> args, DnaData & data)
{
    //slice <seq> <from_ind> <to_ind> [: [@<new_seq_name>|@@]]
//    if (args.size() > 2)
//        m_message = "Invalid Argument :(\n";
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

    SliceDecorator * sliceDecorator = new SliceDecorator(d->getDnaA(), from, to, to-from);
    d->setPtr(sliceDecorator);

    std::string parName = args.back();
    std::stringstream name;
    if (parName == "@@")
        name << d->getName();
    else
    {
        if (parName.substr(0,1) != "@")
            return;
        else
            name << parName.substr(1, parName.length());
    }
    d->setName(name.str());

    std::stringstream ss;
    ss << "[" << d->getId() << "] " << name.str() <<": " << d->getStringDna2() << "\n";
    m_message = ss.str();

}