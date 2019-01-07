//
// Created by cfrenkel on 1/6/19.
//

#include "ReplaceDecorator.h"

ReplaceDecorator::ReplaceDecorator(SharePointer<IDNA> ptr, int index, char new_letter) :
m_dna_ptr(ptr), m_index(index), m_new_letter(new_letter)
{
    if (index > getLength())
        throw "error";
}

int ReplaceDecorator::getLength() const
{
    return m_dna_ptr->getLength();
}

Nucleotide& ReplaceDecorator::operator[](const int index) const
{
    if (index == m_index)
        return *(new Nucleotide(m_new_letter));
    return (*m_dna_ptr)[index];
}