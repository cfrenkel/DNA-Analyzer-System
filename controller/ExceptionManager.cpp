//
// Created by cfrenkel on 1/5/19.
//

#include "ExceptionManager.h"

ExceptionManager::ExceptionManager(int error) :errorCode(error){}
std::map<int, std::string> ExceptionManager::errorCodeMap = ExceptionManager::initMapCode();
std::map<int, std::string> ExceptionManager::initMapCode()
{
    std::map<int, std::string> tempMap;
    tempMap[0] = "Invalid Characters :(\n";
    tempMap[1] = "Not Divide 3 :(\n";
    tempMap[2] = "Index out of range :(\n";
    tempMap[3] = "Invalid Index :(\n";
    tempMap[4] = "Command Not Fount :(\n";
    tempMap[5] = "Invalid Command Or Argument :(\n";
    tempMap[6] = "Invalid Name Of Sequence :(\n";
    return tempMap;
}

std::string ExceptionManager::getMsg()
{
    return errorCodeMap[errorCode];
}
