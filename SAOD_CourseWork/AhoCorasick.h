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
private:
    struct Node {
        std::map<char, int> children;
        int fail; // Ссылка на суффикс, который также является префиксом
        int parent; // Родительский узел
        char parent_char; // Символ, ведущий к этому узлу
        int output; // Индекс конца шаблона, если этот узел является концом шаблона

        Node(int parent, char parent_char) : parent(parent), parent_char(parent_char), fail(0), output(-1) {}
    };

    std::vector<Node> trie;
    std::vector<std::string> patterns;

    void addPattern(const std::string& pattern);
    void buildFailEdges();
    std::vector<int> search(const std::string& text);
public:
    std::vector<int> findSubstring(const std::string& main, const std::string& sub);
};

