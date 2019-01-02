//
// Created by cfrenkel on 12/29/18.
//

#include "../controller/FactoryCommand.h"
#include "../controller/New.h"
#include "../controller/Load.h"
#include "../controller/Save.h"
#include "../controller/Show.h"
#include "../controller/Exit.h"
#include "../controller/Dup.h"
#include "../controller/Rename.h"
#include "../controller/Del.h"

FactoryCommand::FactoryCommand()
{
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("new", new New));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("load", new Load));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("save", new Save));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("show", new Show));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("exit", new Exit));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("dup", new Dup));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("rename", new Rename));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("del", new Del));
}
//
Command* FactoryCommand::getCommand(std::string command)
{
    return commandMap.at(command).get();
}

//SharePointer<FactoryCommand> FactoryCommand:: = SharePointer<FactoryCommand>();
//
//SharedPtr<FactoryCommand> FactoryCommand::getInstance()
//{
//    if (!m_instance)
//    {
//        m_instance = SharedPtr<CommandFactory>(new CommandFactory());
//    }
//
//    return m_instance;
//}

//bool FactoryCommand::registerCommand(std::string command, SharePointer<Command> sp)
//{
//    commandMap[command] = sp;
//    return true;
//}
