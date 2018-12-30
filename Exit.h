//
// Created by cfrenkel on 12/30/18.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXIT_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXIT_H


#include "Command.h"

class Exit : public Command
{
    void action(std::list<std::string>, DnaData &);
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXIT_H
