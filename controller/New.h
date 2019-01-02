//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_NEW_H
#define DNA_NEW_H

#include "../controller/Command.h"

class New : public Command
{
public:
    void action(std::list<std::string>, DnaData &);
//    void help();
};


#endif //DNA_NEW_H
