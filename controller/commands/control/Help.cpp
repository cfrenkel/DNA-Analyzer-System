//
// Created by cfrenkel on 1/16/19.
//

#include "Help.h"

#include "../../admin/Convert.h"
#include "../../factory/FactoryCommand.h"
#include "../../errorManagment/ERROR_CODES.h"

bool Help::reg = FactoryCommand::registerCommand("help", SharePointer<Command>(new Help));

void Help::action(std::list<std::string> args, DnaData & data)
{
    if (args.size() > 1)
        throw INVALID_COMMAND;

    FactoryCommand factoryCommand;

    if (args.size() > 0 )
         m_message = factoryCommand.getCommand(args.front())->help();
    else
    {
        std::stringstream ss;
        std::map<std::string, SharePointer<Command> >::iterator itr;
        for (itr = factoryCommand.getMap().begin(); itr !=  factoryCommand.getMap().end(); ++itr)
            ss << itr->second->help();
        m_message = ss.str();
    }

}

std::string Help::help()
{
     std::stringstream ss;
     ss << "Help: **help**\n";
      return ss.str();
}