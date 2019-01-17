//
// Created by cfrenkel on 1/16/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_CONCATDECORATOR_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_CONCATDECORATOR_H


#include "../../SharePointer.h"
#include "../IDNA.h"
#include <vector>

class ConcatDecorator : public IDNA
{
public:
    ConcatDecorator();

    int getLength() const;
    void addIdna(SharePointer<IDNA>);
    Nucleotide & operator[](const int) const;

private:
    std::vector<SharePointer<IDNA> > m_dna_ptr;
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_CONCATDECORATOR_H
