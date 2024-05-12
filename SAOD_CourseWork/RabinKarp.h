#pragma once
#include "DefineValue.h"

class RabinKarp
{
#pragma region ST
private:
    RabinKarp();
    RabinKarp(RabinKarp&);
    RabinKarp(RabinKarp&&);
    static RabinKarp* instance;
    ~RabinKarp();
public:
    static RabinKarp* GetInstance();
    static void DestroyInstance();
#pragma endregion 

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);
};

