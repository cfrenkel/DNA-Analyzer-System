//
// Created by cfrenkel on 1/16/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_CONCAT_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_CONCAT_H


#include "../Command.h"

class Concat : public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_CONCAT_H
