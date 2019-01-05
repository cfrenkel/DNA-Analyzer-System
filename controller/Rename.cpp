//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Rename.h"
#include "../controller/ERROR_CODES.h"

void Rename::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 2)
        throw INVALID_COMMAND;
    // rename <seq> @<new_name>
    std::string oldDna = args.front();
    std::string newName = args.back().substr(1, args.back().length());

    std::string del = oldDna.substr(0, 1);

    if (del == "#")
    {
        int number = fromString(oldDna.substr(1, oldDna.length()));
        data.changeNameByNumber(newName, number);
    }
    else
    {
        std::string name_of_dna = oldDna.substr(1, oldDna.length());
        data.changeNameByName(newName, name_of_dna);
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(newName) << "] " << newName <<": " << data.getByName(newName).getStringDna2() << "\n";
    m_message = ss.str();
}