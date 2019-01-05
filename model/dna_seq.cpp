//
// Created by cfrenkel on 10/24/18.
//
#include "../model/dna_seq.h"
#include <assert.h>
#include <cstring>
#include "../controller/ERROR_CODES.h"
// -----------------------------------------------  //
// --------------- DNA ---------------------------- //
// ----------------------------------------------- //

void check_seq(const char * seq)
{
    //switch ....
    if (strlen(seq)%3 != 0)
        throw NOT_DIVIDE_3;
}
//DNA::DNA(std::string seq)
//{
//    std::cout << seq << "\n";
//    std::cout << seq.c_str() << "\n";
//    DNA(seq.c_str());
//}
DNA::DNA(std::string seq)
{
    int length = seq.length();
    m_length = length;
    check_seq(seq.c_str());
    DNA_seq = new Nucleotide[length];
    try {
        for (int i = 0; i < length; i++) {
            DNA_seq[i] = toupper(seq[i]);
        }
    }
    catch (char * msg)
    {
        delete []  DNA_seq;
        throw msg;
    }
}
DNA::DNA(char * seq)
{
    int length = strlen(seq);
    m_length = length;
    check_seq(seq);
    DNA_seq = new Nucleotide[length];
    try {
        for (int i = 0; i < length; i++) {
            DNA_seq[i] = toupper(seq[i]);
        }
    }
    catch (int error)
    {
        delete []  DNA_seq;
        throw error;
    }
}
DNA::DNA(const DNA & other)
{
        int length = other.getLength();
        m_length = length;
        DNA_seq = new Nucleotide[length];
        for (int i = 0; i<length; i++)
        {
            DNA_seq[i] = other.DNA_seq[i];
        }
}
DNA& DNA::operator=(const DNA other)
{
    if (this != &other) {
        delete [] DNA_seq;
        int length = other.getLength();
        m_length = length ;
        DNA_seq = new Nucleotide[length];
        for (int i = 0; i<length; i++)
        {
            DNA_seq[i] = other.DNA_seq[i];
        }
    }
    return *this;
}
DNA& DNA::operator=(const char *seq)
{
    if(this != new DNA(seq)) {
        delete[] DNA_seq;
        int length = strlen(seq);
        m_length = length;
        check_seq(seq);
        DNA_seq = new Nucleotide[length];
        try {
            for (int i = 0; i < length; i++) {
                DNA_seq[i] = toupper(seq[i]);
            }
        }
        catch (char * msg)
        {
            delete []  DNA_seq;
            throw msg;
        }
    }
    return *this;
}
DNA& DNA::operator=(const std::string &seq)
{
    delete [] DNA_seq;
    check_seq(seq.c_str());
    int length = strlen(seq.c_str());
    DNA_seq = new Nucleotide[length];
    try {
        for (int i = 0; i < length; i++) {
            DNA_seq[i] = toupper(seq[i]);
        }
    }
    catch (char * msg)
    {
        delete []  DNA_seq;
        throw msg;
    }
    return *this;
}
bool DNA::operator==(const DNA & other) const
{
    if (other.m_length != m_length)
        return false;
    for (size_t i=0; i<this->m_length; i++)
    {
        if (other.DNA_seq[i] != this->DNA_seq[i])
            return false;
    }
    return true;
}
bool DNA::operator!=(const DNA & other)const
{
    if (other.m_length != m_length)
        return true;
    for (size_t i=0; i<this->m_length; i++)
    {
        if (other.DNA_seq[i] != this->DNA_seq[i])
            return true;
    }
    return false;
}
bool DNA::operator==(const char * other) const
{
    if (strlen(other) != m_length)
        return false;
    for (size_t i=0; i<this->m_length; i++)
    {
        if (this->DNA_seq[i] != other[i])
            return false;
    }
    return false;
}
bool DNA::operator!=(const char * other) const
{
    if (strlen(other) != m_length)
        return true;
    for (size_t i=0; i<m_length; i++)
    {
        if (this->DNA_seq[i] != other[i])
            return true;
    }
    return false;
}
Nucleotide & DNA::operator[](const int index) const
{
    if (index>=getLength())
        throw OUT_OF_RANGE;
    return DNA_seq[index];
}
int DNA::getLength() const
{
    return m_length;
}
DNA::~DNA()
{
    if (DNA_seq) {
        delete[] DNA_seq;
    }
}
std::ostream& operator<<(std::ostream&os, const DNA & other)
{
    for (int i=0; i<other.getLength(); i++)
        os<<other.DNA_seq[i];
    return os;
}
std::fstream& operator<<(std::fstream&os, const DNA & other)
{
    for (int i=0; i<other.getLength(); i++)
        os<<other.DNA_seq[i];
    return os;
}
DNA::DNA(const DNA  other, size_t from, size_t to)
{
    if (to > m_length || from<0 || from>to)
        throw INVALID_INDEX;
    size_t length = to - from;
    m_length = length;
    DNA_seq = new Nucleotide[length];
    for (size_t i = 0, j = from; /*i< length,*/ j<to; i++, j++)
    {
        DNA_seq[i] = other.DNA_seq[j];
    }
}
DNA DNA::slice(int from, int to) const
{
    return DNA(*this, from, to);
}
DNA  DNA::pair() const
{
    DNA d(*this);
    for(size_t i = 0; i<m_length; i++)
    {
        d[i] = DNA_seq[m_length - i - 1].pair();
    }
    return d;
}

