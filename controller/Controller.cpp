//
// Created by cfrenkel on 12/27/18.
//

#include "../controller/Controller.h"
#include "../controller/Command.h"
#include "../controller/New.h"
#include "../controller/ExceptionManager.h"
#include "../controller/ERROR_CODES.h"
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

