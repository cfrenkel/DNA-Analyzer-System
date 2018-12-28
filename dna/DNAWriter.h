//
// Created by cfrenkel on 10/29/18.
//

#ifndef DNA_DNAWRITERTXT_H
#define DNA_DNAWRITERTXT_H
#include <fstream>
class DNA;
class DNAWriter
{
public:
    DNAWriter(const char * const name);
    void Write(const DNA& other);
    ~DNAWriter();
private:
    // composition
    std::ofstream myfile;
};
#endif //DNA_DNAWRITERTXT_H
