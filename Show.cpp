//
// Created by cfrenkel on 12/30/18.
//

#include "Show.h"

void Show::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front();
    int number = fromString(s.substr(1, s.length()));
    std::stringstream ss;
    ss << "[" << number << "] " << data.getNameById(number) << ": " << data.getByNumber(number) << " \n";
    m_message = ss.str();
}


