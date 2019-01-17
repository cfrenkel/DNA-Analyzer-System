//
// Created by cfrenkel on 12/30/18.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXIT_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXIT_H


#include "Command.h"

class Exit : public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
    std::string help();
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXIT_H
