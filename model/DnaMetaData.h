//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_DNAMETADATA_H
#define DNA_DNAMETADATA_H

#include "../model/dna_seq.h"
#include "../SharePointer.h"
#include <string>
#include <list>

class DnaMetaData
{
public:
    DnaMetaData(){}
    DnaMetaData(int, std::string, SharePointer<IDNA>);

    bool operator==(const DnaMetaData&);

    void setName(std::string);
    void setPtr(SharePointer<IDNA>);
    void setId(int);

    int getId();
    std::string getName();
    DNA & getDna();
    SharePointer<IDNA> getSharePointerDna();

    std::string getSeqStringDnaWithPar(int size = 99);
    std::string getSeqStringDna();

    std::string getNewSeqName(std::list<std::string>, std::string);
    std::string getNewFileNameBySeq(std::list<std::string>);

    friend std::ostream&operator<<(std::ostream&os, const DnaMetaData & other);

private:
    int m_id;
    std::string m_name;
    SharePointer<IDNA> m_dnaPtr;
};


#endif //DNA_DNAMETADATA_H
