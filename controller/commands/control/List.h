//
// Created by cfrenkel on 1/3/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_LIST_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_LIST_H

#include "../Command.h"

class List :public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
    std::string help();

};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_LIST_H
