//
// Created by cfrenkel on 12/27/18.
//

#include "../view/CommandInterface.h"
#include "iostream"

std::string CommandInterface::input()
{
    std::string command;
    output("> cmd >>> ");
    std::getline(std::cin, command);
    return command;
}
void CommandInterface::output(std::string message)
{
    if (message.length() > 0)
        std::cout << message;
}