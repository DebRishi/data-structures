#include<bits/stdc++.h>
using namespace std;

// LEETCODE 211 - Design Add and Search Words Data Structure
class WordDictionary {
public:
    struct TrieNode {
        bool ends;
        TrieNode* child[26];
        TrieNode() {
            ends = false;
            for(int i = 0 ; i < 26 ; i++)
                child[i] = 0;
        }
    };
    
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(auto c : word) {
            if(!node->child[c-'a'])
                node->child[c-'a'] = new TrieNode();
            node = node->child[c-'a'];
        }
        node->ends = true;
    }
    
    bool search(string word) {
        return find(root,word);
    }
    
    bool find(TrieNode* node,string word,int i = 0) {
        int n = word.length();
        if(i == n) 
            return node->ends;
        if(word[i] == '.') {
            for(auto next : node->child)
                if(next && find(next,word,i+1))
                    return true;
            return false;
        }
        else if(node->child[word[i]-'a'])
            return find(node->child[word[i]-'a'],word,i+1);
        else
            return false;
    }
};

int main() {
    return 0;
}