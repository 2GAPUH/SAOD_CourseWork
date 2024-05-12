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

std::vector<int> KMP::buildPrefixTable(const std::string& pattern)
{
    int n = pattern.size();
    std::vector<int> prefix(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

std::vector<int> KMP::findSubstring(const std::string& main, const std::string& sub)
{
    std::vector<int> positions;
    if (sub.empty() || main.empty()) return positions;

    std::vector<int> prefix = buildPrefixTable(sub);
    int m = main.length();
    int n = sub.length();
    int j = 0;

    for (int i = 0; i < m; i++) {
        while (j > 0 && main[i] != sub[j]) {
            j = prefix[j - 1];
        }
        if (main[i] == sub[j]) {
            if (j == n - 1) {
                positions.push_back(i - n + 1); // добавляем позицию начала шаблона в тексте
                j = prefix[j]; // продолжаем поиск следующего вхождения
            }
            else {
                j++;
            }
        }
    }

    return positions;
}
