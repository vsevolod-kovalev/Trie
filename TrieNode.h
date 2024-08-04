#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>
#include <string>

class TrieNode {
    bool isWord;
    std::unordered_map<char, TrieNode*> children;

    TrieNode(const TrieNode&) = delete;
    TrieNode& operator=(const TrieNode&) = delete;

    public:
        TrieNode() : isWord(false) {}
        ~TrieNode() {
            for (auto& pair : children) {
                delete pair.second;
            }
        }
        void insert(const std::string& s) {
            TrieNode* current = this;
            for (const auto& c : s) {
                if (current->children.find(c) == current->children.end()) {
                    TrieNode* new_node = new TrieNode();
                    current->children.insert({c, new_node});
                }
                current = current->children.at(c);
            }
            current->isWord = true;
        }
        bool search(const std::string& s) {
            TrieNode* current = this;
            for (const auto& c : s) {
                if (current->children.find(c) == current->children.end()) {
                    return false;
                }
                current = current->children.at(c);
            }
            return current->isWord;
        }
        bool searchPrefix(const std::string& s) {
            TrieNode* current = this; 
            for (const auto& c : s) {
                if (current->children.find(c) == current->children.end()) {
                    return false;
                }
                current = current->children.at(c);
            }
            return true;
        }
};

#endif // TRIENODE_H    