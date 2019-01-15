//
// Created by cfrenkel on 1/2/19.
//

#include "../model/SliceDecorator.h"
#include "Slice.h"
#include "../controller/Convert.h"


void Slice::action(std::list<std::string> args, DnaData & data)
{
    //slice <seq> <from_ind> <to_ind> [: [@<new_seq_name>|@@]]

    if (args.size() < 3 || args.size() > 4)
       m_message = "Invalid Argument :(\n";

    std::string s = args.front();
    DnaMetaData & d = data.getDnaByArgs(s);

    args.pop_front();
    int from = Convert::fromString(args.front());
    args.pop_front();
    int to = Convert::fromString(args.front());
    args.pop_front();

    std::string name;
    SharePointer<SliceDecorator> sliceDecor(new SliceDecorator(d.getSharePointerDna(), from, to, to-from));

    if (args.size() < 1) {
        d.setPtr(sliceDecor);
        name = d.getName();
    }
    else
    {
        name = d.getNewSeqName(args, "s");
        data.newDnaByIdna(name, sliceDecor);
    }

    std::stringstream ss;
    ss << "[" << data.getIdByName(name) << "] " << name <<": " << data.getByNumber(data.getIdByName(name)).getSeqStringDna()<< "\n";
    m_message = ss.str();

}