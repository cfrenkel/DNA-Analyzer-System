//
// Created by cfrenkel on 1/2/19.
//

#include "Necleotide.h"
#include <cstring>
#include <assert.h>
#include "../../controller/errorManagment/ERROR_CODES.h"
// ----------------------------------------------- //
// --------------- Nucleotide --------------------- //
// ----------------------------------------------- //

void check_nucleotid(const char nuc)
{
    char c = toupper(nuc);
    if (c != 'A' && c != 'G' && c!='T' && c!='C')
    {
        throw  INVALID_CHARACTER;
    }
}
Nucleotide::Nucleotide(const char nuc)
{
    check_nucleotid(nuc);
    nucleotide = toupper(nuc);
}
Nucleotide::Nucleotide() : nucleotide('A')
{
}
Nucleotide::Nucleotide(const Nucleotide & other)
{
    if(this!=&other)
    {
        nucleotide = other.nucleotide;
    }
}
Nucleotide::~Nucleotide()
{

}
Nucleotide & Nucleotide::operator=(const Nucleotide other)
{
    if(this!=&other)
    {
        this->nucleotide = other.nucleotide;
    }
    return *this;
}
Nucleotide & Nucleotide::operator=(const char nuc)
{
    check_nucleotid(nuc);
    if(this->nucleotide!=nuc)
    {
        this->nucleotide = nuc;
    }
    return *this;

}
bool Nucleotide::operator==(const Nucleotide & other) const
{
    return other.nucleotide == this->nucleotide;
}
bool Nucleotide::operator!=(const Nucleotide & other) const
{
    return !(this->nucleotide==other.nucleotide);
}
bool Nucleotide::operator==(const char c) const
{
    return this->nucleotide==toupper(c);
}
bool Nucleotide::operator!=(const char c) const
{
    return !(this->nucleotide==toupper(c));
}
//Nucleotide::operator Nucleotide() const
//{
//    // return this;
//}
Nucleotide::operator char() const
{
    return nucleotide;
}
Nucleotide & Nucleotide::pair() const
{
    switch (nucleotide)
    {
        case 'C':
            return *(new Nucleotide('G'));
        case 'G':
            return *(new Nucleotide('C'));
        case 'T':
            return *(new Nucleotide('A'));
        case 'A':
            return *(new Nucleotide('T'));
        default:
            assert("Invalid Charter\n");
    }
    throw INVALID_CHARACTER;
}
std::ostream& operator<<(std::ostream&os, Nucleotide & other)
{
    os<<other.nucleotide;
    return os;
}