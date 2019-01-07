//
// Created by cfrenkel on 1/6/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_REPLACEDECORATOR_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_REPLACEDECORATOR_H

#include "../SharePointer.h"
#include "../model/IDNA.h"

class ReplaceDecorator : public IDNA
{
public:
    int getLength() const;
    Nucleotide & operator[](const int) const;
    ReplaceDecorator(SharePointer<IDNA>, int, char);

private:
    SharePointer<IDNA> m_dna_ptr;
    int m_index;
    char m_new_letter;
};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_REPLACEDECORATOR_H
