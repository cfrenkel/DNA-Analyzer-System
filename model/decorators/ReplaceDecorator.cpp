//
// Created by cfrenkel on 1/6/19.
//

#include "ReplaceDecorator.h"

ReplaceDecorator::ReplaceDecorator(SharePointer<IDNA> ptr) :
m_dna_ptr(ptr)
{}

int ReplaceDecorator::getLength() const
{
    return m_dna_ptr->getLength();
}

void ReplaceDecorator::addPair(int index, char n)
{
    m_index_neclutide.insert(std::pair<int, char>(index, n));
}

Nucleotide & ReplaceDecorator::operator[](const int index) const
{
    if (m_index_neclutide.find(index) != m_index_neclutide.end())
        return *(new Nucleotide(m_index_neclutide.at(index)));
    return (*m_dna_ptr)[index];
}