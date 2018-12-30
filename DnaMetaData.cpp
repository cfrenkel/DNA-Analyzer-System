//
// Created by cfrenkel on 12/27/18.
//

#include "DnaMetaData.h"

DnaMetaData::DnaMetaData(int id, std::string name,DNA * d)
{
    m_id = id;
    m_name = name;
    m_dnaPtr = d;
}

bool DnaMetaData::operator==(const DnaMetaData & d)
{
    return *d.m_dnaPtr == *m_dnaPtr && d.m_name == m_name && d.m_id == m_id;
}
DNA & DnaMetaData::getDna()
{
    return *m_dnaPtr;
}
std::ostream& operator<<(std::ostream&os, const DnaMetaData & other)
{
    os << *other.m_dnaPtr;
    return os;
}