//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Dup.h"

std::string getName(int number, DnaData & data)
{
    static int id = 1;
    std::string name = data.getNameById(number);
    std::stringstream ss;
    ss << name << "_" << id++;
    name = ss.str();
    return name;
}

void Dup::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front(); //dup from
    std::string del = s.substr(0, 1);

    std::string name;
    if (del == "#")
    {
        int number = fromString(s.substr(1, s.length()));
        if (args.size() > 1)
            name = args.back().substr(1,args.back().length()); // name copy
        else
            name = getName(number, data);
        data.newDnaByDna(name, data.getByNumber(number));
    }
    else
    {
        if (del != "@")
        {
            throw "Invalid Name Of Sequence\n";
        }
        std::string seqName = s.substr(1, s.length());
        if (args.size() > 1)
            name = args.back().substr(1,args.back().length());
        else
            name = getName(data.getIdByName(seqName), data);
        data.newDnaByDna(name, data.getByName(name));
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getIdByName(name) << "\n";
    m_message = ss.str();
}


