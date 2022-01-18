#include<iostream>
using namespace std;

// LEETCODE 208
class Trie {
    struct TrieNode {
        int ends;
        TrieNode* child[26];
        TrieNode() : ends(0) {
            for(int i = 0 ; i < 26 ; i++)
                child[i] = 0;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* head = root;
        for(char c : word) {
            if(!head->child[c-'a'])
                head->child[c-'a'] = new TrieNode();
            head = head->child[c-'a'];
        }
        head->ends = 1;
    }
    
    bool search(string word) {
        TrieNode* head = root;
        for(char c : word) {
            if(!head->child[c-'a'])
                return false;
            head = head->child[c-'a'];
        }
        if(!head->ends)
            return false;
        else
            return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* head = root;
        for(char c : prefix) {
            if(!head->child[c-'a'])
                return false;
            head = head->child[c-'a'];
        }
        if(!head)
            return false;
        else
            return true;
    }
};

int main() {
    return 0;
}