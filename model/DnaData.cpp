//
// Created by cfrenkel on 12/27/18.
//

#include "../model/DnaData.h"
#include "../model/DnaMetaData.h"
#include "../controller/ERROR_CODES.h"
#include <sstream>
int DnaData::number = 0;

void DnaData::newDna(std::string name, std::string dna)
{
    DNA * d;
    try {
             d = new DNA(dna);
        }
    catch (const char * mes)
    {
        delete d;
        throw mes;
    }
//    delete d

    SharePointer<DNA> d1(d);
    ++number;
    dna_id_map.insert(std::pair<int, DnaMetaData>(number, DnaMetaData(number, name, d1)));
    dna_string_map.insert(std::pair<std::string,DnaMetaData>(name, DnaMetaData(number,name, d1)));
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
}
void DnaData::newDna(std::string name, DNA dna)
{
    ++number;
    SharePointer<DNA> d;
    try {
        d = new DNA(dna);
    }
    catch (ERROR_CODE err)
    {
        --number;
        throw err;
    }
    dna_id_map.insert(std::pair<int,DnaMetaData>(number, DnaMetaData(number,name, d)));
    dna_string_map.insert(std::pair<std::string,DnaMetaData>(name, DnaMetaData(number,name, d)));
//    printNameMap();
//    printIdMap();
}
int DnaData::getIdByName(std::string name)
{
    DnaMetaData dd = getByName(name);
    std::map<int,DnaMetaData>::iterator itr;
    for(itr = dna_id_map.begin() ; itr!= dna_id_map.end() ; itr++)
    {
        if (itr->second == dd)
        {
            return itr->first;
        }
    }
    return -1;
}
std::string DnaData::getNameById(int number)
{
    DnaMetaData dd = getByNumber(number);
    std::map<std::string,DnaMetaData>::iterator itr;
    for(itr = dna_string_map.begin() ; itr!= dna_string_map.end() ; itr++)
    {
        if (itr->second == dd)
        {
            return itr->first;
        }
    }
    return "Not Exist\n";
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
    if (dna_id_map.find(number) == dna_id_map.end())
        throw NOT_EXIST_SEQ;
    return dna_id_map.at(number);
}
DnaMetaData & DnaData::getByName(std::string name)
{
    if (dna_string_map.find(name) == dna_string_map.end())
        throw NOT_EXIST_SEQ;
    return dna_string_map.at(name);
}
void DnaData::changeNameByName(std::string newName, std::string oldName)
{
    DnaMetaData dd = getByName(oldName);
    dd.setName(newName);

    dna_string_map.erase(oldName);
    dna_string_map.insert(std::pair<std::string,DnaMetaData>(newName, dd));
    dna_id_map.erase(dd.getId());
    dna_id_map.insert(std::pair<int,DnaMetaData>(dd.getId(), dd));

}
void DnaData::changeNameByNumber(std::string newName, int number)
{
    DnaMetaData dd = getByNumber(number);
    dd.setName(newName);

    dna_string_map.erase(dd.getName());
    dna_string_map.insert(std::pair<std::string,DnaMetaData>(newName, dd));
    dna_id_map.erase(number);
    dna_id_map.insert(std::pair<int,DnaMetaData>(number, dd));
}
int DnaData::getSeqNumber()
{
    return number + 1;
}
int DnaData::getLength(DnaMetaData & d)
{
    return d.getDna().getLength();
}
std::string DnaData::getAllSeq()
{
    std::map<int, DnaMetaData>::iterator itr;
    std::stringstream ss;
    for (itr = dna_id_map.begin(); itr != dna_id_map.end(); itr++) {
        ss << "[" << itr->first << "] " << getNameById(itr->first) << ":" << itr->second.getStringDna2() << "\n";
    }
    return ss.str();
}