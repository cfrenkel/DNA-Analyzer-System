//
// Created by cfrenkel on 12/27/18.
//

#ifndef DNA_DNADATA_H
#define DNA_DNADATA_H

#include "DnaMetaData.h"
#include <map>
class DnaData
{
public:
//    DnaData();
    void newDna(std::string, std::string);
    void newDnaByDna(std::string, DnaMetaData);
    void newDna(std::string, DNA);
    int getIdByName(std::string);
    std::string getNameById(int);
    void printNameMap();
    void printIdMap();

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
