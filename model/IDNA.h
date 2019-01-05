//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_IDNA_H
#define DNA_IDNA_H

#include "../model/Necleotide.h"
class IDNA
{
public:
    virtual int getLength() const = 0;
    virtual Nucleotide & operator[](const int) const = 0;
    virtual ~IDNA(){}
};
#endif //DNA_IDNA_H
