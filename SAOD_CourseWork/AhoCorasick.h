#pragma once
#include "DefineValue.h"

class AhoCorasick
{
#pragma region ST
private:
    AhoCorasick();
    AhoCorasick(AhoCorasick&);
    AhoCorasick(AhoCorasick&&);
    static AhoCorasick* instance;
    ~AhoCorasick();
public:
    static AhoCorasick* GetInstance();
    static void DestroyInstance();
#pragma endregion 

public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);
};

