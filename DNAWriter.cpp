//
// Created by cfrenkel on 10/29/18.
//

#include "DNAWriter.h"
#include "dna_seq.h"

DNAWriter::DNAWriter(std::string name)
{
    myfile.open(name.c_str());
}
void DNAWriter::Write(const DNA & other)
{
    myfile<<other;
    myfile.close();
}
DNAWriter::~DNAWriter()
{
    myfile.close();
}