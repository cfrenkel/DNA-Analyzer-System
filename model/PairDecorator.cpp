//
// Created by cfrenkel on 1/6/19.
//


#include "PairDecorator.h"

PairDecorator::PairDecorator(SharePointer<IDNA> pointer) : m_dna_ptr(pointer) {}

int PairDecorator::getLength() const
{
    return m_dna_ptr->getLength();
}

Nucleotide & PairDecorator::operator[](const int index) const
{
    return (*m_dna_ptr)[index].pair();
}