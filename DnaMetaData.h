//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_DNAMETADATA_H
#define DNA_DNAMETADATA_H

#include "dna_seq.h"
#include "SharePointer.h"
#include <string>

class DnaMetaData
{
public:
    DnaMetaData(int, std::string, DNA *);
    bool operator==(const DnaMetaData&);
    DNA & getDna();
    friend std::ostream&operator<<(std::ostream&os, const DnaMetaData & other);



private:
    int m_id;
    std::string m_name;
    SharePointer<DNA> m_dnaPtr;
};


#endif //DNA_DNAMETADATA_H
