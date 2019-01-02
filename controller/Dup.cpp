//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Dup.h"

void Dup::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front();
    std::string del = s.substr(0, 1);
    std::string name = args.back().substr(1,args.back().length());

    if (del == "#")
    {
        int number = fromString(s.substr(1, s.length()));
        data.newDnaByDna(name, data.getByNumber(number));
    }
    else
    {
        std::string name_of_dna = s.substr(1, s.length());
        data.newDnaByDna(name, data.getByName(name_of_dna));
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getIdByName(name) << "\n";
    m_message = ss.str();
}