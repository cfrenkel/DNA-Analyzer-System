//
// Created by cfrenkel on 1/6/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_REPLACE_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_REPLACE_H

#include "Command.h"


class Replace : public Command
{
public:
    void action(std::list<std::string>, DnaData &);
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_REPLACE_H
