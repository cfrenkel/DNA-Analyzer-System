//
// Created by cfrenkel on 1/5/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_PAIR_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_PAIR_H

#include "../controller/Command.h"

class Pair :public Command
{
public:
    void action(std::list<std::string>, DnaData &);
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_PAIR_H
