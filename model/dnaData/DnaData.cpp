//
// Created by cfrenkel on 12/27/18.
//

#include "DnaData.h"
#include "DnaMetaData.h"
#include "../../controller/errorManagment/ERROR_CODES.h"
#include "../../controller/admin/Convert.h"
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
//    printIdMap();
//    printNameMap();
}

void DnaData::newDnaByIdna(std::string name, SharePointer<IDNA> dna)
{
    ++number;
    dna_id_map.insert(std::pair<int,DnaMetaData>(number, DnaMetaData(number,name, dna)));
    dna_string_map.insert(std::pair<std::string,DnaMetaData>(name, DnaMetaData(number,name, dna)));
//    printNameMap();
//    printIdMap();
}

int DnaData::getIdByName(std::string name)
{
    DnaMetaData dd = getByName(name);
    return dd.getId();
}

std::string DnaData::getNameById(int number)
{
    DnaMetaData dd = getByNumber(number);
    return dd.getName();
}

void DnaData::printIdMap()
{
    std::map<int,DnaMetaData>::iterator itr;
    for(itr = dna_id_map.begin() ; itr!= dna_id_map.end() ; itr++)
    {
        DnaMetaData d = itr->second;
        std::cout << "Id: " << itr->first << " dna: " << itr->second.getDna() << "\n";
    }
}

void DnaData::printNameMap()
{
    std::map<std::string,DnaMetaData>::iterator itr;
    for(itr = dna_string_map.begin() ; itr!= dna_string_map.end() ; itr++)
    {
        std::cout << "name: " << itr->first << " dna: " << itr->second.getDna() << "\n";
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
        ss << "[" << itr->first << "] " << itr->second.getName() << ":" << itr->second.getSeqStringDna() << "\n";
    }
    return ss.str();
}

DnaMetaData & DnaData::getDnaByArgs(std::string s)
{
    std::string del = s.substr(0, 1);
    std::string name;

    if (del == "#")
    {
        int number = Convert::fromString(s.substr(1, s.length()));
        return getByNumber(number);
    }
    else
    {
        if (del != "@") {
            throw INVALID_NAME_SEQ;
        }
        std::string seqName = s.substr(1, s.length());
        return getByName(name);
    }
}

std::string DnaData::getNameDnaByArgs(std::list<std::string> args)
{
    std::string name;
    if (args.size() == 1)
    {
        std::string del = args.front().substr(0,1);
        if (del != "@")
        {
            throw INVALID_NAME_SEQ;
        }
        name = args.back().substr(1,args.back().length());
    }
    else
    {
        std::stringstream ss;
        ss << "seq" << getSeqNumber();
        name = ss.str();
    }
    return name;
}