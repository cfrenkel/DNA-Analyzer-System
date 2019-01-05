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
#include "../controller/List.h"
#include "../controller/Pair.h"
#include "../controller/ERROR_CODES.h"
FactoryCommand::FactoryCommand()
{
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("new", SharePointer<Command>(new New)));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("load", SharePointer<Command>(new Load)));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("save", SharePointer<Command>(new Save)));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("show", SharePointer<Command>(new Show)));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("exit", SharePointer<Command>(new Exit)));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("dup", SharePointer<Command>(new Dup)));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("rename", SharePointer<Command>(new Rename)));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("del", SharePointer<Command>(new Del)));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("list", SharePointer<Command>(new List)));
    commandMap.insert(std::pair<std::string,SharePointer<Command> >("pair", SharePointer<Command>(new Pair)));

}

Command * FactoryCommand::getCommand(std::string command)
{
    if (commandMap.find(command) == commandMap.end())
    {
        throw NOT_FOUND_COAMMAND;
    }
    return commandMap[command].get();
}

////SharePointer<FactoryCommand> FactoryCommand:: = SharePointer<FactoryCommand>();
////
//SharePointer<FactoryCommand> FactoryCommand::getInstance()
//{
//    if (!m_instance)
//    {
//        m_instance = SharePointer<FactoryCommand>(new FactoryCommand());
//    }
//
//    return m_instance;
//}
//
//bool FactoryCommand::registerCommand(std::string command, SharePointer<Command> sp)
//{
//    commandMap[command] = sp;
//    return true;
//}
