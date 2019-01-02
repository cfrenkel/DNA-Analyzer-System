//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_COMMANDINTERFACE_H
#define DNA_COMMANDINTERFACE_H

#include "../view/UserInterface.h"
#include <iostream>

class CommandInterface /*: public UserInterface*/
{
public:
    std::string input();
    void output(std::string);

};


#endif //DNA_COMMANDINTERFACE_H
