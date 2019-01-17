//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_CONTROLLER_H
#define DNA_CONTROLLER_H

#include <string>
#include <list>
#include "../view/Parser.h"
#include "../model/dnaData/DnaData.h"
#include "../controller/factory/FactoryCommand.h"
#include "../view/CommandInterface.h"

class Controller
{
public:
    void run();

private:
    CommandInterface commandInterface;
    std::list<std::string> recentCommand;
    Parser m_parser;
    DnaData m_dnaData;
    FactoryCommand factoryCommand;
};


#endif //DNA_CONTROLLER_H
