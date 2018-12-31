#include "DNAReader.h"
//
// Created by cfrenkel on 10/29/18.
//

DNAReader::DNAReader(std::string name)
{
    myfile.open(name.c_str());
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