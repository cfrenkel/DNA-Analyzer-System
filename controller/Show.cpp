//
// Created by cfrenkel on 12/30/18.
//

#include "../controller/Show.h"
#include "FactoryCommand.h"


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
    int size;
    if (args.size() > 1) {
        size = fromString(args.back());
        if (size > data.getLength(d))
            size = data.getLength(d);
    }
    else {
        if (99 > data.getLength(d))
            size = data.getLength(d);
    }
    ss << data.getByNumber(d.getId()).getDna().slice(0, size) << "\n";
    m_message = ss.str();
}


