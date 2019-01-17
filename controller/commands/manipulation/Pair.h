//
// Created by cfrenkel on 1/5/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_PAIR_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_PAIR_H

#include "../Command.h"

class Pair :public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
    std::string help();

};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_PAIR_H
