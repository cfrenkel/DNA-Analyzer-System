//
// Created by cfrenkel on 1/16/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_COUNT_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_COUNT_H

#include "../Command.h"

class Count :public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
    std::string help();
};

#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_COUNT_H
