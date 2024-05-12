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
private:
    void initializeHashAndPower(const std::string& str, int& hash, int& power);
    int recalculateHash(int oldHash, char oldChar, char newChar, int power);
    bool compareStrings(const std::string& text, int start, const std::string& pattern);

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);
};

