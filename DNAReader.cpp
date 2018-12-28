#include "DNAReader.h"
#include "dna_seq.h"
//
// Created by cfrenkel on 10/29/18.
//

DNAReader::DNAReader(const char * const name)
{
    myfile.open(name);
}
DNA  DNAReader::read()
{
    myfile.seekg (0, std::ios::end);
    int length = myfile.tellg();
    myfile.seekg(0);
    char * output = new char[length+1];
    while (!myfile.eof()) {
        myfile >> output;
    }
    DNA d(output);
    delete[] output;
    return d;
}
DNAReader::~DNAReader()
{
    myfile.close();
}