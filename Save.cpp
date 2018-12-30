//
// Created by cfrenkel on 12/29/18.
//

#include "Save.h"
#include "DNAWriter.h"

void Save::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front();
    int number = fromString(s.substr(1, s.length()));

    DNAWriter writer(args.back());
    writer.Write(data.getByNumber(number).getDna());
}
