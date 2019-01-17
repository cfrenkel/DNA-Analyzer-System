//
// Created by cfrenkel on 1/6/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_REPLACEDECORATOR_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_REPLACEDECORATOR_H

#include <map>
#include "../../SharePointer.h"
#include "../IDNA.h"

class ReplaceDecorator : public IDNA
{
public:
    int getLength() const;
    Nucleotide & operator[](const int) const;
    ReplaceDecorator(SharePointer<IDNA>);
    void addPair(int, char);

private:
    SharePointer<IDNA> m_dna_ptr;
    std::map<int, char> m_index_neclutide;
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_REPLACEDECORATOR_H
