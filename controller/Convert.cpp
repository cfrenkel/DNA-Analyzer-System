//
// Created by cfrenkel on 1/15/19.
//

#include <sstream>
#include "Convert.h"

int Convert::fromString(std::string s)
{
    int value;
    std::stringstream ss( s );
    ss >> value;
    return value;
}