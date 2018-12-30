//
// Created by cfrenkel on 12/29/18.
//

#include "Save.h"
#include "DNAWriter.h"
void Save::action(std::list<std::string> args, DnaData & data)
{
    DNAWriter writer(args.back());
    writer.Write(DNA(args.front()));
}
