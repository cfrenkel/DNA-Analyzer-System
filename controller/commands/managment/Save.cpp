//
// Created by cfrenkel on 12/29/18.
//

#include "Save.h"
#include "../../../model/readWriteDna/DNAWriter.h"
#include "../../errorManagment/ERROR_CODES.h"
#include "../../factory/FactoryCommand.h"

bool Save::reg = FactoryCommand::registerCommand("save", SharePointer<Command>(new Save));

void Save::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 2)
        throw INVALID_COMMAND;

    DnaMetaData & metaData = data.getDnaByArgs(args.front());
    args.pop_front();

    DNAWriter writer(metaData.getNewFileNameBySeq(args));
    writer.Write(metaData.getSharePointerDna());

}

std::string Save::help()
{
    std::stringstream ss;
    ss << "Save: ** **\n\n";

    return ss.str();
}