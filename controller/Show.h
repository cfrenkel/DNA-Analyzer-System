//
// Created by cfrenkel on 12/30/18.
//

#ifndef DNA_SHOW_H
#define DNA_SHOW_H

#include "../controller/Command.h"


class Show: public Command
{
    void action(std::list<std::string>, DnaData &);
    int initSize(std::list<std::string> , int );
};


#endif //DNA_SHOW_H
