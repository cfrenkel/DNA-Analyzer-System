//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_DNAMETADATA_H
#define DNA_DNAMETADATA_H

#include "../model/dna_seq.h"
#include "../SharePointer.h"
#include <string>

class DnaMetaData
{
public:
    DnaMetaData(){}
    DnaMetaData(int, std::string, SharePointer<IDNA>);
    bool operator==(const DnaMetaData&);
    DNA & getDna();
    SharePointer<IDNA> getDnaA();
    void setId(int);
    int getId();
    std::string getName();
    void setName(std::string);
    void setPtr(IDNA * );
    std::string getStringDna(int size = 99);
    std::string getStringDna2();
    friend std::ostream&operator<<(std::ostream&os, const DnaMetaData & other);



private:
    int m_id;
    std::string m_name;
    SharePointer<IDNA> m_dnaPtr;
};


#endif //DNA_DNAMETADATA_H
