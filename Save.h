//
// Created by cfrenkel on 12/29/18.
//

#ifndef DNA_SAVE_H
#define DNA_SAVE_H


#include "Command.h"

class Save : public Command
{
    void action(std::list<std::string>, DnaData &);
};


#endif //DNA_SAVE_H
