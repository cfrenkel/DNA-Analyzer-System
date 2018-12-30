//
// Created by cfrenkel on 12/27/18.
//

#include "DnaData.h"
#include "DnaMetaData.h"

int DnaData::number = 0;

void DnaData::newDna(std::string name, std::string dna)
{
    try {
            DNA * d = new DNA(dna);
        }
    catch (const char * mes)
    {
        throw mes;
    }
//    delete d;
    ++number;
    dna_id_map.insert(std::pair<int, DnaMetaData>(number, DnaMetaData(number, name, new DNA(dna))));
    dna_string_map.insert(std::pair<std::string,DnaMetaData>(name, DnaMetaData(number,name, new DNA(dna))));
//    printNameMap();
//    printIdMap();
}

void DnaData::newDnaByDna(std::string name, DnaMetaData dna)
{
    ++number;
    dna.setId(number);
    dna.setName(name);
    dna_id_map.insert(std::pair<int, DnaMetaData>(number, dna));
    dna_string_map.insert(std::pair<std::string,DnaMetaData>(name, dna));
//    printNameMap();
//    printIdMap();
}
void DnaData::newDna(std::string name, DNA dna)
{
    ++number;
    try {
    dna_id_map.insert(std::pair<int,DnaMetaData>(number, DnaMetaData(number,name, &dna)));
    }
    catch (char * mes)
    {
        throw mes;
    }
    dna_string_map.insert(std::pair<std::string,DnaMetaData>(name, DnaMetaData(number,name, &dna)));
//    printNameMap();
//    printIdMap();
}
int DnaData::getIdByName(std::string name)
{
    DnaMetaData dd = dna_string_map.at(name);
    std::map<int,DnaMetaData>::iterator itr;
    for(itr = dna_id_map.begin() ; itr!= dna_id_map.end() ; itr++)
    {
        if (itr->second == dd)
        {
            return itr->first;
        }
    }
}
std::string DnaData::getNameById(int number)
{
    DnaMetaData dd = dna_id_map.at(number);
    std::map<std::string,DnaMetaData>::iterator itr;
    for(itr = dna_string_map.begin() ; itr!= dna_string_map.end() ; itr++)
    {
        if (itr->second == dd)
        {
            return itr->first;
        }
    }
}
void DnaData::printIdMap()
{

    std::map<int,DnaMetaData>::iterator itr;
    std::cout << dna_id_map.size() << " \n";
    for(itr = dna_id_map.begin() ; itr!= dna_id_map.end() ; itr++)
    {
        DnaMetaData d = itr->second;
        std::cout << "Id: " << itr->first << " dna: " << itr->second << "\n";
    }
}
void DnaData::printNameMap()
{
    std::cout << dna_id_map.size() << " \n";
    std::map<std::string,DnaMetaData>::iterator itr;
    for(itr = dna_string_map.begin() ; itr!= dna_string_map.end() ; itr++)
    {
        std::cout << "name: " << itr->first << " dna: " << itr->second << "\n";
    }
}
DnaMetaData & DnaData::getByNumber(int number)
{
    return dna_id_map.at(number);
}
DnaMetaData& DnaData::getByName(std::string name)
{
    return dna_string_map.at(name);
}