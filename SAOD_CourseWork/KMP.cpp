#include "KMP.h"

KMP* KMP::instance = nullptr;

KMP::KMP()
{
}

KMP::~KMP()
{
}

KMP* KMP::GetInstance()
{
    if (instance == nullptr)
        instance = new KMP();
    return instance;
}

void KMP::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

std::vector<int> KMP::findSubstring(const std::string& main, const std::string& sub)
{
    return std::vector<int>();
}
