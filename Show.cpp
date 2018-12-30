//
// Created by cfrenkel on 12/30/18.
//

#include <sstream>
#include "Show.h"

int fromString( std::string s )
{
    int value;
    std::stringstream ss( s );
    ss >> value;
    return value;
}

void Show::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front();
    int number = fromString(s.substr(1, s.length()));
    std:: cout << "[" << number << "] " << data.getNameById(number) << ": " << data.getByNumber(number) << " \n";
}


