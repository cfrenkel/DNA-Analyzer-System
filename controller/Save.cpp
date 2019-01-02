//
// Created by cfrenkel on 12/29/18.
//

#include "../controller/Save.h"
#include "../model/DNAWriter.h"

void Save::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front();
    std::string del = s.substr(0, 1);
    std::string name = args.back().substr(1,args.back().length());
    DNAWriter writer(args.back());
    if (del == "#")
    {
        int number = fromString(s.substr(1, s.length()));
        writer.Write(data.getByNumber(number).getDna());
    }
    else
    {
        std::string name_of_dna = s.substr(1, s.length());
        writer.Write(data.getByName(name_of_dna).getDna());
    }

}
