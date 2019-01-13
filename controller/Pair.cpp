//
// Created by cfrenkel on 1/5/19.
//

#include "../model/PairDecorator.h"
#include "Pair.h"
#include "../controller/ERROR_CODES.h"
#include "../controller/ExceptionManager.h"

std::string calcException(ERROR_CODE e)
{
    return ExceptionManager(e).getMsg();
}

void Pair::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 3)
    {
        m_message = calcException(INVALID_COMMAND);
        return;
    }
    std::string s = args.front(); //pair from
    std::string del = s.substr(0, 1);

    DnaMetaData  * d;
    if (del == "#")
    {
        int number = fromString(s.substr(1, s.length()));
        d = &(data.getByNumber(number));
    }
    else
    {
        if (del != "@")
        {
            m_message = calcException(INVALID_COMMAND);
            return;
        }
        std::string seqName = s.substr(1, s.length());
        d = &(data.getByName(seqName));
    }
    SharePointer<PairDecorator> pairDecorator(new PairDecorator(d->getDnaA()));

    std::string parName = args.back();
    std::stringstream name;
    if (parName == "@@")
        name << d->getName() << "_p" << d->getId();
    else
    {
        if (parName.substr(0,1) != "@")
        {
            m_message = calcException(INVALID_COMMAND);
            return;
        }
        else
            name << parName.substr(1, parName.length());
    }

    data.newDnaByIdna(name.str(), pairDecorator);

    std::stringstream ss;
    ss << "[" << data.getIdByName(name.str()) << "] " << name.str() <<": " << data.getByName(name.str()).getStringDna2()<< "\n";
    m_message = ss.str();

}
