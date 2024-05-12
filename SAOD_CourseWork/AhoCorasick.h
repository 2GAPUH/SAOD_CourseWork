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
        int fail; // ������ �� �������, ������� ����� �������� ���������
        int parent; // ������������ ����
        char parent_char; // ������, ������� � ����� ����
        int output; // ������ ����� �������, ���� ���� ���� �������� ������ �������

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

