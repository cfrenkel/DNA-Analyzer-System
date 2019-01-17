//
// Created by cfrenkel on 10/29/18.
//

#include "DNAWriter.h"
#include "../sequences/dna_seq.h"
#include "../../controller/errorManagment/ERROR_CODES.h"

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