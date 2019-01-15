//
// Created by cfrenkel on 10/24/18.
//

#ifndef DNA_SEQ_H
#define DNA_SEQ_H

#include <iostream>
#include <fstream>
#include "../model/IDNA.h"
#include "../model/Necleotide.h"


class DNA : public IDNA
{
    public:

    DNA(std::string seq);
    DNA(char * seq);
    DNA(const DNA & other);

    DNA& operator=(const DNA other);
    DNA& operator=(const char * seq);
    DNA& operator=(const std::string & seq);

    bool operator==(const DNA & other) const;
    bool operator!=(const DNA & other) const;
    bool operator==(const char * other) const;
    bool operator!=(const char * other) const;

    Nucleotide & operator[](const int index) const;
    int getLength() const;

    ~DNA();

    friend std::ostream&operator<<(std::ostream&os, const DNA & other);
    friend std::fstream&operator<<(std::fstream&os, const DNA & other);

    DNA slice(int from, int to) const;
    DNA pair() const;

    private:

        DNA(const DNA  other, size_t from, size_t to);
        DNA(const DNA  other, size_t len);
        Nucleotide * DNA_seq;
        unsigned int  m_length;

};
#endif //DNA_SEQ_H
