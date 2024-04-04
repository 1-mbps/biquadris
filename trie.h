#ifndef __TRIE_H__
#define __TRIE_H__
#include <memory>
#include <string>

using namespace std;

class Trie {
    
    class TrieNode {
        friend class Trie;
        shared_ptr<TrieNode> children[26];
        bool is_terminal = true;
        bool is_word = false;
        int num_subtrees = 1;
        int successor_index = -1;
        string word;

        public:
            TrieNode();
            void insert(string key, size_t start);
            string return_closest_match(string key, size_t start);
            string end_of_branch();
    };

    shared_ptr<TrieNode> root = make_shared<TrieNode>();

    public:
        Trie();

        // Inserts a string into the trie
        void insert(string key);

        // Returns the closest match to a command if it's valid
        // Returns "NOT FOUND" is it's not valid
        string return_closest_match(string key);

};

#endif
