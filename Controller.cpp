//
// Created by cfrenkel on 12/27/18.
//

#include "Controller.h"
#include "Command.h"
#include "New.h"
#include <iterator>

void printParser(std::list<std::string> par)
{
    std::cout << "in controller run " << par.size() << "\n";

    par.pop_front();
    for(std::list<std::string>::iterator itr = par.begin(); itr!=  par.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << "\n";
}

void Controller::run(std::string command)
{
    recentCommand.push_front(command);
    std::list<std::string> par = m_parser.parse(command);
    Command * c;
    try {
        c = factoryCommand.getCommand(par.front());
    }
    catch (...)
    {
        std::cout << "Command Not Found :( \n";
        return;
    }
    par.pop_front();
    try {
        c->action(par, m_dnaData);
    }
    catch (const char * message)
    {
        std::cout << message << "\n";
        return;
    }
    //printParser(par);

}

