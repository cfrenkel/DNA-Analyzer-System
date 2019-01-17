//
// Created by cfrenkel on 12/30/18.
//

#include "Show.h"
#include "../../factory/FactoryCommand.h"
#include "../../errorManagment/ERROR_CODES.h"
#include "../../admin/Convert.h"

bool Show::reg = FactoryCommand::registerCommand("show", SharePointer<Command>(new Show));


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


std::string Show::help()
{
    std::stringstream ss;
    ss << "show: **show `<seq>` [<num_chars>]**\n";
    ss << "Shows the sequence: Its ID, its name, its status\n";
    ss << "and <num_chars> (or default if not exist <num_chars>) characters\n";
    ss << "of the sequence itself\n\n";

    return ss.str();
}