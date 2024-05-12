#include "RabinKarp.h"

RabinKarp* RabinKarp::instance = nullptr;

RabinKarp::RabinKarp()
{
}

RabinKarp::~RabinKarp()
{
}

RabinKarp* RabinKarp::GetInstance()
{
    if (instance == nullptr)
        instance = new RabinKarp();
    return instance;
}

void RabinKarp::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

std::vector<int> RabinKarp::findSubstring(const std::string& main, const std::string& sub)
{
    return std::vector<int>();
}
