#include "AhoCorasick.h"

AhoCorasick* AhoCorasick::instance = nullptr;

AhoCorasick::AhoCorasick()
{
}

AhoCorasick::~AhoCorasick()
{
}

AhoCorasick* AhoCorasick::GetInstance()
{
    if (instance == nullptr)
        instance = new AhoCorasick();
    return instance;
}

void AhoCorasick::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

std::vector<int> AhoCorasick::findSubstring(const std::string& main, const std::string& sub)
{
    return std::vector<int>();
}
