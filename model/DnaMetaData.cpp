//
// Created by cfrenkel on 12/27/18.
//

#include <sstream>
#include "../model/DnaMetaData.h"

DnaMetaData::DnaMetaData(int id, std::string name,SharePointer<IDNA> d)
{
    m_id = id;
    m_name = name;
    m_dnaPtr = d;
}

bool DnaMetaData::operator==(const DnaMetaData & d)
{
    return d.m_dnaPtr == m_dnaPtr && d.m_name == m_name && d.m_id == m_id;
}
DNA & DnaMetaData::getDna()
{
    return *((DNA*)m_dnaPtr.get());
}
std::ostream& operator<<(std::ostream&os, const DnaMetaData & other)
{
    os << *((DNA*)other.m_dnaPtr.get());
    return os;
}

void DnaMetaData::setId(int id)
{
    m_id = id;
}
int DnaMetaData::getId()
{
    return m_id;
}
std::string DnaMetaData::getName()
{
    return m_name;
}
void DnaMetaData::setName(std::string name)
{
    m_name = name;
}

std::string DnaMetaData::getStringDna(int size)
{
    std::stringstream ss;
    size_t len = std::min(size, m_dnaPtr->getLength());
    for( int i = 0; i < len; ++i)
    {
        ss << (*m_dnaPtr)[i];
    }
    return ss.str();
}