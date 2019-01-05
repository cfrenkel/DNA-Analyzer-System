//
// Created by cfrenkel on 1/5/19.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXEPTIONMANAGER_H
#define EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXEPTIONMANAGER_H


#include <string>
#include <map>

class ExceptionManager
{
public:
    ExceptionManager(int);
    std::string getMsg();

private:
    int errorCode;
    static std::map<int, std::string> initMapCode();
    static std::map<int, std::string> errorCodeMap;

};


#endif //EXCELLENTEAM_ELLA_C_DNA_CFRENKEL_EXEPTIONMANAGER_H
