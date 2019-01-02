//
// Created by cfrenkel on 12/29/18.
//

#include "../controller/Save.h"
#include "../model/DNAWriter.h"

std::string getFileName(std::string name)
{
    std::stringstream ss;
    ss << name << ".rawdna";
    name = ss.str();
    return name;
}
void Save::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front();   // seq name
    std::string del = s.substr(0, 1);

    std::string name = args.back().substr(1,args.back().length()); // file name
    //.rawdna


    if (del == "#")
    {
        int number = fromString(s.substr(1, s.length()));
        if (args.size() > 1) {
            DNAWriter writer(args.back());
            writer.Write(data.getByNumber(number).getDna());
        }
        else {
            DNAWriter writer(getFileName(data.getNameById(number)));
            writer.Write(data.getByNumber(number).getDna());
        }

    }
    else
    {
        std::string name_of_dna = s.substr(1, s.length());
        if (args.size() > 1) {
            DNAWriter writer(args.back());
            writer.Write(data.getByName(name_of_dna).getDna());
        }
        else {
            DNAWriter writer(getFileName(name_of_dna));
            writer.Write(data.getByName(name_of_dna).getDna());
        }
    }

}
