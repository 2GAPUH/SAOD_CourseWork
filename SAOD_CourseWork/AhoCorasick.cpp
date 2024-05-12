#include "AhoCorasick.h"

AhoCorasick* AhoCorasick::instance = nullptr;

AhoCorasick::AhoCorasick()
{
    trie.emplace_back(0, '\0');
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
    addPattern(sub);
    buildFailEdges();
    return search(main);
}

void AhoCorasick::addPattern(const std::string& pattern)
{
    int node = 0;
    for (char c : pattern) {
        if (trie[node].children.find(c) == trie[node].children.end()) {
            trie[node].children[c] = trie.size();
            trie.emplace_back(node, c);
        }
        node = trie[node].children[c];
    }
    int output = patterns.size();
    trie[node].output = output;
    patterns.push_back(pattern);
}

void AhoCorasick::buildFailEdges()
{
    std::queue<int> queue;
    for (auto& p : trie[0].children) {
        queue.push(p.second);
        trie[p.second].fail = 0;
    }

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        for (auto& p : trie[current].children) {
            char symbol = p.first;
            int child = p.second;
            int fail = trie[current].fail;

            while (fail && trie[fail].children.find(symbol) == trie[fail].children.end()) {
                fail = trie[fail].fail;
            }

            if (trie[fail].children.find(symbol) != trie[fail].children.end()) {
                fail = trie[fail].children[symbol];
            }

            trie[child].fail = fail;

            if (trie[fail].output != -1) {
                trie[child].output = trie[fail].output;
            }

            queue.push(child);
        }
    }
}

std::vector<int> AhoCorasick::search(const std::string& main)
{
    std::vector<int> results;
    int node = 0;
    int size = main.size();

    for (int i = 0; i < size; i++) {
        char c = main[i];

        while (node && trie[node].children.find(c) == trie[node].children.end()) {
            node = trie[node].fail;
        }

        if (trie[node].children.find(c) != trie[node].children.end()) {
            node = trie[node].children[c];
        }

        if (trie[node].output != -1) {
            results.push_back(i - patterns[trie[node].output].size() + 1);
        }
    }

    return results;
}
