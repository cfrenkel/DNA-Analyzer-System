//
// Created by cfrenkel on 12/30/18.
//

#ifndef DNA_SHOW_H
#define DNA_SHOW_H

#include "../Command.h"


class Show: public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
    std::string help();

};


#endif //DNA_SHOW_H
