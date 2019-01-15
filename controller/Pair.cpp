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
    std::string name;
    if (args.size() > 3)
    {
        m_message = calcException(INVALID_COMMAND);
        return;
    }
    std::string s = args.front(); //pair from

    DnaMetaData & d = data.getDnaByArgs(s);

    SharePointer<PairDecorator> pairDecorator(new PairDecorator(d.getSharePointerDna()));

    args.pop_front();

    name = d.getNewSeqName(args, "p");

    data.newDnaByIdna(name, pairDecorator);

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getByName(name).getSeqStringDna() << "\n";
    m_message = ss.str();

}
