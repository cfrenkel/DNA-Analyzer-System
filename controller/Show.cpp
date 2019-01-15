//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Show.h"
#include "FactoryCommand.h"
#include "../controller/ERROR_CODES.h"
#include "../controller/Convert.h"


void Show::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 2)
        throw INVALID_COMMAND;
    std::string s = args.front();

    // show `<seq>` [<num_chars>]
    DnaMetaData & d = data.getDnaByArgs(s);

    std::stringstream ss;
    ss << "[" << d.getId() << "] " << d.getName() << ": " ;

    ss << d.getSeqStringDnaWithPar(args.size() > 1? Convert::fromString(args.back()): 99) << "\n";
    m_message = ss.str();
}


