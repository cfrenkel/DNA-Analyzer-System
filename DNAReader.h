//
// Created by cfrenkel on 10/29/18.
//

#ifndef DNA_DNAREADERTXT_H
#define DNA_DNAREADERTXT_H

#include <fstream>
class DNA;

class DNAReader
{
    public:
        DNAReader(const char * const name);
        DNA read();
        ~DNAReader();
    private:
        std::ifstream myfile;
};
#endif //DNA_DNAREADERTXT_H