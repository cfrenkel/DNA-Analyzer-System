//
// Created by cfrenkel on 1/6/19.
//

#include "SliceDecorator.h"

SliceDecorator::SliceDecorator(SharePointer<IDNA> ptr, std::size_t from, std::size_t to, std::size_t length):
m_dna_ptr(ptr), m_from(from), m_to(to), m_length(length)
{

}
int SliceDecorator::getLength() const
{
    return m_length;
}
Nucleotide& SliceDecorator::operator[](const int index) const
{
    return (*m_dna_ptr)[index + m_from];
}