#ifndef __TRIE_H__
#define __TRIE_H__
#include <memory>
#include <string>

using namespace std;

class Trie {
    
    class TrieNode {
        friend class Trie;
        shared_ptr<TrieNode> children[26];
        // bool is_terminal = true;
        bool is_word = false;
        int num_subtrees = 1;
        string word;

        public:
            TrieNode();
            void insert(string key, size_t start);
            bool in_trie(string key, size_t start);
    };

    shared_ptr<TrieNode> root = make_shared<TrieNode>();

    public:
        Trie();

        void insert(string key);

        bool in_trie(string key);

};

#endif
