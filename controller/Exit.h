//
// Created by cfrenkel on 12/30/18.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXIT_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXIT_H


#include "../controller/Command.h"

class Exit : public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXIT_H
