//
// Created by cfrenkel on 1/6/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_PAIRDECORATOR_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_PAIRDECORATOR_H

#include "../SharePointer.h"
#include "../model/IDNA.h"

class PairDecorator : public IDNA {
public:
    int getLength() const;
    Nucleotide & operator[](const int) const;
    PairDecorator(SharePointer<IDNA>);

private:
    SharePointer<IDNA> m_dna_ptr;
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_PAIRDECORATOR_H
