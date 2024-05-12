#include "BoyerMoore.h"

BoyerMoore* BoyerMoore::instance = nullptr;

BoyerMoore::BoyerMoore()
{
}

BoyerMoore::~BoyerMoore()
{
}

BoyerMoore* BoyerMoore::GetInstance()
{
    if (instance == nullptr)
        instance = new BoyerMoore();
    return instance;
}

void BoyerMoore::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

std::vector<int> BoyerMoore::findSubstring(const std::string& main, const std::string& sub)
{
    return std::vector<int>();
}
