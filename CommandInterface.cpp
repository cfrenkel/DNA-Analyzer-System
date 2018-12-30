//
// Created by cfrenkel on 12/27/18.
//

#include "CommandInterface.h"
#include "iostream"


void CommandInterface::run()
{
    std::string command;
    do
    {
        std::cout << "<<< ";
        std::getline(std::cin, command);
//        std::cout << command << "\n";
        if (command != "exit")
        {
            ctrl.run(command);
        }
    }
    while (command != "exit");
    std::cout << "Good By :) \n";
}