//
// Created by cfrenkel on 1/2/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_NECLEOTIDE_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_NECLEOTIDE_H
#include <iostream>
#include <fstream>

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
//    operator Nucleotide() const;
    operator char() const ;
    Nucleotide pair() const;

    //convert
};

#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_NECLEOTIDE_H
