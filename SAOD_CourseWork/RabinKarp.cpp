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

void RabinKarp::initializeHashAndPower(const std::string& str, int& hash, int& power)
{
    for (int i = 0; i < str.length(); i++) {
        hash = (ASCII_SIZE * hash + str[i]) % PRIME;
        if (i < str.length() - 1) {
            power = (power * ASCII_SIZE) % PRIME;
        }
    }
}

int RabinKarp::recalculateHash(int oldHash, char oldChar, char newChar, int power)
{
    int newHash = (ASCII_SIZE * (oldHash - oldChar * power) + newChar) % PRIME;
    if (newHash < 0) newHash += PRIME;
    return newHash;
}

bool RabinKarp::compareStrings(const std::string& main, int start, const std::string& sub)
{
    for (int i = 0; i < sub.length(); i++) {
        if (main[start + i] != sub[i]) {
            return false;
        }
    }
    return true;
}

std::vector<int> RabinKarp::findSubstring(const std::string& main, const std::string& sub)
{
    std::vector<int> positions;
    if (sub.length() > main.length()) return positions;

    int patternHash = 0, textHash = 0, power = 1;

    // Инициализация хешей и степени d
    initializeHashAndPower(sub, patternHash, power);
    initializeHashAndPower(main.substr(0, sub.length()), textHash, power);

    // Поиск шаблона в тексте
    for (int i = 0; i <= main.length() - sub.length(); i++) {
        if (patternHash == textHash) {
            if (compareStrings(main, i, sub)) {
                positions.push_back(i);
            }
        }
        if (i < main.length() - sub.length()) {
            textHash = recalculateHash(textHash, main[i], main[i + sub.length()], power);
        }
    }

    return positions;
}
