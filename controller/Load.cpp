//
// Created by cfrenkel on 12/29/18.
//

#include "../controller/Load.h"
#include "../model/DNAReader.h"

void Load::action(std::list<std::string> args, DnaData &data)
{
    std::string name;
    if (args.size() > 1)
    {
        std::string del = args.back().substr(0,1);
        if (del != "@")
        {
            throw "Invalid Name Of Sequence\n";
        }
        name = args.back().substr(1,args.back().length());
    }
    else
    {
        std::stringstream ss;
        ss << "seq" << data.getSeqNumber();
        name = ss.str();
    }
    DNAReader reader(args.front());
    std::string dna = reader.read();
    data.newDna(name, dna);

    std::stringstream ss;
    int id = data.getIdByName(name);
    ss << "[" << data.getIdByName(name) << "] " <<name<<": " << dna <<"\n";
    m_message = ss.str();
    //    data.printNameMap();
    //    data.printIdMap();
}