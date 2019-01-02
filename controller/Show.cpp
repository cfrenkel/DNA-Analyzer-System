//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Show.h"

void Show::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front();
    std::string del = s.substr(0, 1);

    DnaMetaData d;
    if (del == "#") {
         d = data.getByNumber(fromString(s.substr(1, s.length())));
    }
    else
    {
         d = data.getByName(s.substr(1, s.length()));
    }
    std::stringstream ss;
    ss << "[" << d.getId() << "] " << d.getName() << ": " << data.getByNumber(d.getId()) << " \n";
    m_message = ss.str();
}

