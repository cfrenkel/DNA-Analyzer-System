//
// Created by cfrenkel on 1/5/19.
//

#include "../../../model/decorators/PairDecorator.h"
#include "Pair.h"
#include "../../admin/Convert.h"
#include "../../factory/FactoryCommand.h"

#include "../../errorManagment/ERROR_CODES.h"
#include "../../errorManagment/ExceptionManager.h"


bool Pair::reg = FactoryCommand::registerCommand("pair", SharePointer<Command>(new Pair));

std::string calcExceptionPair(ERROR_CODE e)
{
    return ExceptionManager(e).getMsg();
}

void Pair::action(std::list<std::string> args, DnaData & data)
{
    std::string name;
    if (args.size() > 3)
    {
        m_message = calcExceptionPair(INVALID_COMMAND);
        return;
    }
    std::string s = args.front(); //pair from

    DnaMetaData & d = data.getDnaByArgs(s);

    SharePointer<PairDecorator> pairDecorator(new PairDecorator(d.getSharePointerDna()));

    args.pop_front();


    if (args.size() < 1) {
        d.setPtr(pairDecorator);
        name = d.getName();
    }
    else
    {
        name = d.getNewSeqName(args, "p");
        data.newDnaByIdna(name, pairDecorator);
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getByNumber(data.getIdByName(name)).getSeqStringDna() << "\n";
    m_message = ss.str();

}

std::string Pair::help()
{
    std::stringstream ss;
    ss << "Pair: ** **\n\n";

    return ss.str();
}