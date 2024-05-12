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

std::vector<int> BoyerMoore::buildBadCharTable(const std::string& sub)
{
    int m = sub.size();
    std::vector<int> badCharTable(256, -1);
    for (int i = 0; i < m; ++i) {
        badCharTable[static_cast<unsigned char>(sub[i])] = i;
    }
    return badCharTable;
}

std::vector<int> BoyerMoore::buildGoodSuffixTable(const std::string& sub)
{
    int m = sub.size();
    std::vector<int> goodSuffixTable(m + 1, m);
    std::vector<int> borderPos(m + 1, 0);
    int i = m, j = m + 1;
    borderPos[i] = j;

    while (i > 0) {
        while (j <= m && sub[i - 1] != sub[j - 1]) {
            if (goodSuffixTable[j] == m) {
                goodSuffixTable[j] = m - i;
            }
            j = borderPos[j];
        }
        i--; j--;
        borderPos[i] = j;
    }

    j = borderPos[0];
    for (i = 0; i <= m; i++) {
        if (goodSuffixTable[i] == m) {
            goodSuffixTable[i] = j;
        }
        if (i == j) {
            j = borderPos[j];
        }
    }
    return goodSuffixTable;
}

std::vector<int> BoyerMoore::findSubstring(const std::string& main, const std::string& sub)
{
    int n = main.size();
    int m = sub.size();
    std::vector<int> positions;
    if (m > n) return positions;

    auto badCharTable = buildBadCharTable(sub);
    auto goodSuffixTable = buildGoodSuffixTable(sub);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && sub[j] == main[s + j]) {
            j--;
        }
        if (j < 0) {
            positions.push_back(s);
            s += goodSuffixTable[0];
        }
        else {
            s += std::max(goodSuffixTable[j + 1], j - badCharTable[static_cast<unsigned char>(main[s + j])]);
        }
    }
    return positions;
}
