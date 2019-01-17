//
// Created by cfrenkel on 1/6/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_SLICEDECORATOR_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_SLICEDECORATOR_H

#include "../../SharePointer.h"
#include "../IDNA.h"

class SliceDecorator : public IDNA
{
public:
    int getLength() const;
    Nucleotide & operator[](const int) const;
    SliceDecorator(SharePointer<IDNA>, std::size_t, std::size_t, std::size_t);

private:
    SharePointer<IDNA> m_dna_ptr;
    std::size_t m_from;
    std::size_t m_to;
    std::size_t m_length;
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_SLICEDECORATOR_H
