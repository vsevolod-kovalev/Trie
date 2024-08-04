#include <iostream>
#include "TrieNode.h"

int main() {
    std::string s = "hello";
    TrieNode trie;
    trie.insert("joker");
    std::cout << trie.search("jokers") << std::endl; // 0
    std::cout << trie.search("joker") << std::endl; // 1
    std::cout << trie.search("joke") << std::endl; // 0
    std::cout << trie.searchPrefix("joke") << std::endl; // 1
    std::cout << trie.searchPrefix("a") << std::endl; // 0
    return 0;
}