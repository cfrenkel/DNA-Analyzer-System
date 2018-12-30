//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_COMMANDINTERFACE_H
#define DNA_COMMANDINTERFACE_H

#include "UserInterface.h"
#include "Controller.h"

class CommandInterface /*: public UserInterface*/
{

public:
    void run();
    void exit();

private:
    Controller ctrl;
};


#endif //DNA_COMMANDINTERFACE_H
