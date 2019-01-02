//
// Created by cfrenkel on 10/24/18.
//

#ifndef DNA_SEQ_H
#define DNA_SEQ_H
#include <iostream>
#include <fstream>
#include "../model/IDNA.h"


class DNA : public IDNA
{
    public:
    // ************************ //
    // **** Nucleotide Class *** //
    // ************************ //
    class Nucleotide
    {
        private:
            char nucleotide;
        public:
            explicit Nucleotide(const char nuc);
            Nucleotide();
            Nucleotide(const Nucleotide & other);
            ~Nucleotide();

            Nucleotide & operator=(const Nucleotide other);
            Nucleotide & operator=(const char nuc);

            bool operator==(const Nucleotide & other) const;
            bool operator!=(const Nucleotide & other) const;
            bool operator==(const char c) const;
            bool operator!=(const char c) const;

            friend std::ostream&operator<<(std::ostream&os, Nucleotide & other);
            operator Nucleotide() const;
            operator char() const ;
            Nucleotide pair() const;

            //convert
    };

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
        DNA(const DNA  other, int from, int to);
        DNA(const DNA  other, int len);
        Nucleotide * DNA_seq;
        unsigned int  m_length;

};
#endif //DNA_SEQ_H
