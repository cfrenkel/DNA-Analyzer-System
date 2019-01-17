//
// Created by cfrenkel on 1/6/19.
//


#include "ConcatDecorator.h"

ConcatDecorator::ConcatDecorator()
{

}

void ConcatDecorator::addIdna(SharePointer<IDNA> idna)
{
    m_dna_ptr.push_back(idna);
}

int ConcatDecorator::getLength() const
{
    int sum = 0;
    for ( int i = 0; i< m_dna_ptr.size(); ++i)
        sum += m_dna_ptr[i]->getLength();
    return sum;
}

Nucleotide & ConcatDecorator::operator[](const int index) const
{
    if (index > getLength())
        throw "invalid index \n";
    int current_index = 0;
    int current_sum = 0;
    for ( int i = 0; i< m_dna_ptr.size(); ++i)
    {
        current_sum += m_dna_ptr[i].get()->getLength();
        if (index >= current_index && index <= current_sum - 1 )
            return (*m_dna_ptr[i])[index - current_index];
        current_index += m_dna_ptr[i].get()->getLength();
    }

}