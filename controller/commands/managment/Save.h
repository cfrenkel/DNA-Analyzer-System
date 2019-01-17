//
// Created by cfrenkel on 12/29/18.
//

#ifndef DNA_SAVE_H
#define DNA_SAVE_H


#include "../Command.h"

class Save : public Command
{
    static bool reg;
public:
    void action(std::list<std::string>, DnaData &);
    std::string help();

};


#endif //DNA_SAVE_H
