//
// Created by cfrenkel on 1/5/19.
//

#include "../model/PairDecorator.h"
#include "Pair.h"
#include "../controller/ERROR_CODES.h"

void Pair::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 3)
        throw INVALID_COMMAND;

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
            throw INVALID_NAME_SEQ;
        }
        std::string seqName = s.substr(1, s.length());
        d = &(data.getByName(seqName));
    }

    PairDecorator * sliceDecorator = new PairDecorator(d->getDnaA());
    d->setPtr(sliceDecorator);

    std::string parName = args.back();
    std::stringstream name;
    if (parName == "@@")
        name << d->getName() << "_p" << d->getId();
    else
    {
        if (parName.substr(0,1) != "@")
            throw INVALID_COMMAND;
        else
            name << parName.substr(1, parName.length());
    }
    // [24] short_seq_s1_repl_seq_c1_p1: ACGGATCGTA

    d->setName(name.str());
    std::stringstream ss;
    ss << "[" << d->getId() << "] " << name.str() <<": " << d->getStringDna2() << "\n";
    m_message = ss.str();

}