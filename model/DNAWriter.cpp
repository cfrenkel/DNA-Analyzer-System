//
// Created by cfrenkel on 10/29/18.
//

#include "../model/DNAWriter.h"
#include "../model/dna_seq.h"
#include "../controller/ERROR_CODES.h"

DNAWriter::DNAWriter(std::string name)
{
    myfile.open(name.c_str());
    if (!myfile.is_open())
        throw FILE_NOT_FOUND;
}
void DNAWriter::Write(const SharePointer<IDNA> other)
{
    for (int i = 0; i<other->getLength(); ++i)
        myfile << (*other)[i];
    myfile.close();
}
DNAWriter::~DNAWriter()
{
    myfile.close();
}