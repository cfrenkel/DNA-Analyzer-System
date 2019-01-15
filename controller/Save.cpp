//
// Created by cfrenkel on 12/29/18.
//

#include "../controller/Save.h"
#include "../model/DNAWriter.h"
#include "../controller/ERROR_CODES.h"

void Save::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 2)
        throw INVALID_COMMAND;

    DnaMetaData & metaData = data.getDnaByArgs(args.front());
    args.pop_front();

    DNAWriter writer(metaData.getNewFileNameBySeq(args));
    writer.Write(metaData.getSharePointerDna());

}
