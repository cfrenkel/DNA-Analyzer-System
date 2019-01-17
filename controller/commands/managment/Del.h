//
// Created by cfrenkel on 12/30/18.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_DEL_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_DEL_H


#include "../Command.h"

class Del : public Command
{
    void action(std::list<std::string>, DnaData &);
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_DEL_H
