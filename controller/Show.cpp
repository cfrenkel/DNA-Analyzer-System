//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Show.h"
#include "FactoryCommand.h"

int Show::initSize(std::list<std::string> args, int length)
{
    int size = 99;
    if (args.size() > 1) {
        size = fromString(args.back());
        if (size > length)
            size = length;
    }
    else {
        if (size > length)
            size = length;

    }
    return size;
}

void Show::action(std::list<std::string> args, DnaData & data)
{
    std::string s = args.front();
    std::string del = s.substr(0, 1);

    // show `<seq>` [<num_chars>]
    DnaMetaData d;
    if (del == "#") {
         d = data.getByNumber(fromString(s.substr(1, s.length())));
    }
    else
    {
         d = data.getByName(s.substr(1, s.length()));
    }
    std::stringstream ss;
    ss << "[" << d.getId() << "] " << d.getName() << ": " ;

    ss << data.getByNumber(d.getId()).getStringDna(initSize(args, data.getLength(d))) << "\n";
    m_message = ss.str();
}


