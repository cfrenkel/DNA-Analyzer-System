//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_NEW_H
#define DNA_NEW_H

#include "../Command.h"

class New : public Command
{
    static bool reg;
    std::string help();

public:
    void action(std::list<std::string>, DnaData &);
//    void help();
};


#endif //DNA_NEW_H
