//
// Created by cfrenkel on 12/29/18.
//

#ifndef DNA_LOAD_H
#define DNA_LOAD_H


#include "../controller/Command.h"

class Load : public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
};


#endif //DNA_LOAD_H
