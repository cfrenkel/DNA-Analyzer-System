//
// Created by cfrenkel on 10/29/18.
//

#ifndef DNA_DNAWRITERTXT_H
#define DNA_DNAWRITERTXT_H
#include <fstream>
#include "../../SharePointer.h"

class IDNA;
class DNAWriter
{
    public:
        DNAWriter(std::string);
        void Write(const SharePointer<IDNA> other);
        ~DNAWriter();
    private:
        // composition
        std::ofstream myfile;
};
#endif //DNA_DNAWRITERTXT_H
