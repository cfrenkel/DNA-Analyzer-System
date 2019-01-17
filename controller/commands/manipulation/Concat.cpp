//
// Created by cfrenkel on 1/16/19.
//


// > cmd >>> concat <seq_1> <seq_2> [: [@<new_seq_name>|@@]]

//
// Created by cfrenkel on 1/5/19.
//

#include "../../../model/decorators/ConcatDecorator.h"
#include "Concat.h"
#include "../../admin/Convert.h"
#include "../../factory/FactoryCommand.h"

#include "../../errorManagment/ERROR_CODES.h"
#include "../../errorManagment/ExceptionManager.h"


bool Concat::reg = FactoryCommand::registerCommand("concat", SharePointer<Command>(new Concat));

std::string calcException(ERROR_CODE e)
{
    return ExceptionManager(e).getMsg();
}
// > cmd >>> concat <seq_1> <seq_2> [: [@<new_seq_name>|@@]]
void Concat::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front();
    std::string name;

    SharePointer<ConcatDecorator> concatDecor(new ConcatDecorator);

    DnaMetaData & d = data.getDnaByArgs(s);

    concatDecor.get()->addIdna(d.getSharePointerDna());

    args.pop_front();

    while (args.size() != 0 && args.front().substr(0, 1) != "@")
    {
        s = args.front();
        concatDecor.get()->addIdna(data.getDnaByArgs(s).getSharePointerDna());
        args.pop_front();
    }


    if (args.size() < 1) {
        d.setPtr(concatDecor);
        name = d.getName();
    }
    else
    {
        name = d.getNewSeqName(args, "c");
        data.newDnaByIdna(name, concatDecor);
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getByNumber(data.getIdByName(name)).getSeqStringDna() << "\n";
    m_message = ss.str();

}
