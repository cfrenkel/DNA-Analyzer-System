//
// Created by cfrenkel on 1/3/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_LIST_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_LIST_H

#include "Command.h"

class List :public Command
{
    void action(std::list<std::string>, DnaData &);
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_LIST_H
