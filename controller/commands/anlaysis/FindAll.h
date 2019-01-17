//
// Created by cfrenkel on 1/16/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_FINDALL_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_FINDALL_H


#include "../Command.h"

class FindAll :public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
    std::string help();
};



#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_FINDALL_H
