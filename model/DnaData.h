//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_DNADATA_H
#define DNA_DNADATA_H

#include "../model/DnaMetaData.h"
#include <map>
class DnaData
{
public:
//    DnaData();
    void newDna(std::string, std::string);
    void newDnaByDna(std::string, DnaMetaData);
    void newDnaByIdna(std::string, SharePointer<IDNA>);

    int getIdByName(std::string);
    std::string getNameById(int);
    std::string getAllSeq();

    void printNameMap();
    void printIdMap();

    int getSeqNumber();
    int getLength(DnaMetaData &);

    DnaMetaData & getByNumber(int);
    DnaMetaData & getByName(std::string);

    void changeNameByName(std::string, std::string);
    void changeNameByNumber(std::string, int);

private:
    static int number;
    std::map<int,DnaMetaData> dna_id_map;
    std::map<std::string, DnaMetaData> dna_string_map;
};


#endif //DNA_DNADATA_H
