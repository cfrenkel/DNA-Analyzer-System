//
// Created by cfrenkel on 10/29/18.
//

#include "DNAWriter.h"
#include "dna_seq.h"

DNAWriter::DNAWriter(const char * const name)
{
    myfile.open(name);
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