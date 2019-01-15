//
// Created by cfrenkel on 12/30/18.
//

#ifndef DNA_SHOW_H
#define DNA_SHOW_H

#include "../controller/Command.h"


class Show: public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
};


#endif //DNA_SHOW_H
