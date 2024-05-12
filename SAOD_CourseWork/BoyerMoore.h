#pragma once
#include "DefineValue.h"    

class BoyerMoore
{
#pragma region ST
private:
    BoyerMoore();
    BoyerMoore(BoyerMoore&);
    BoyerMoore(BoyerMoore&&);
    static BoyerMoore* instance;
    ~BoyerMoore();
public:
    static BoyerMoore* GetInstance();
    static void DestroyInstance();
#pragma endregion 

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);
};

