#pragma once
#include "DefineValue.h"

class KMP
{
#pragma region ST
private:
    KMP();
    KMP(KMP&);
    KMP(KMP&&);
    static KMP* instance;
    ~KMP();
public:
    static KMP* GetInstance();
    static void DestroyInstance();
#pragma endregion 

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);
};

