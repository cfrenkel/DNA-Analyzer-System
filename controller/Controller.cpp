//
// Created by cfrenkel on 12/27/18.
//

#include "Controller.h"
#include "commands/Command.h"
#include "errorManagment/ExceptionManager.h"
#include "errorManagment/ERROR_CODES.h"
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

void Controller::run()
{
    while (true)
    {
        std::string command = commandInterface.input();
        recentCommand.push_front(command);
        std::list<std::string> par = m_parser.parse(command);
        Command *c;
        try {
            c = factoryCommand.getCommand(par.front());
            par.pop_front();
            c->action(par, m_dnaData);
            commandInterface.output(c->m_message);
        }
        catch (ERROR_CODE error) {
            commandInterface.output(ExceptionManager(error).getMsg());
        }
        //printParser(par);
    }

}

