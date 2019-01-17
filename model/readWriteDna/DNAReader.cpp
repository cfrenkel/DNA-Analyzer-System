#include "DNAReader.h"
#include "../../controller/errorManagment/ERROR_CODES.h"
//
// Created by cfrenkel on 10/29/18.
//

DNAReader::DNAReader(std::string name)
{
    myfile.open(name.c_str());
    if (!myfile.is_open())
        throw FILE_NOT_FOUND;
}
std::string  DNAReader::read()
{
    myfile.seekg (0, std::ios::end);
    int length = myfile.tellg();
    myfile.seekg(0);
    char * output = new char[length+1];
    while (!myfile.eof()) {
        myfile >> output;
    }
    return output;
}
DNAReader::~DNAReader()
{
    myfile.close();
}