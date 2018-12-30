//
// Created by cfrenkel on 12/29/18.
//

#ifndef DNA_LOAD_H
#define DNA_LOAD_H


#include "Command.h"

class Load : public Command
{
    void action(std::list<std::string>, DnaData &);
};


#endif //DNA_LOAD_H
