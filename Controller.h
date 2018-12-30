//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_CONTROLLER_H
#define DNA_CONTROLLER_H


#include <string>
#include <list>
#include "Parser.h"
#include "DnaData.h"
#include "FactoryCommand.h"

class Controller
{
public:
    void run(std::string);

private:
    std::list<std::string> recentCommand;
    Parser m_parser;
    DnaData m_dnaData;
    FactoryCommand factoryCommand;
};


#endif //DNA_CONTROLLER_H