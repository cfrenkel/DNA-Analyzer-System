//
// Created by cfrenkel on 12/29/18.
//

#include "Load.h"
#include "DNAReader.h"

void Load::action(std::list<std::string> args, DnaData &data)
{
    DNAReader reader(args.front());
    std::string dna = reader.read();
    data.newDna(args.back(), dna);

    std::stringstream ss;
    ss << "[" << data.getIdByName(args.back()) << "] " <<args.back()<<": " << dna <<"\n";
    m_message = ss.str();
    //    data.printNameMap();
    //    data.printIdMap();
}