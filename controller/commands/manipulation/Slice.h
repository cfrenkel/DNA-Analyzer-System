//
// Created by cfrenkel on 1/2/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_SLICE_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_SLICE_H

#include "../Command.h"

class Slice : public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_SLICE_H
