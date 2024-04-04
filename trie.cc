#include "trie.h"

using namespace std;

Trie::TrieNode::TrieNode() {
    for (int i = 0; i < 26; ++i) { children[i] = nullptr; }
}

void Trie::TrieNode::insert(string key, size_t start) {
    if (start == key.length()-1) {
        shared_ptr<TrieNode> new_node = make_shared<TrieNode>();
        new_node->word = key;
        new_node->is_word = true;
        children[key[start]-'a'] = new_node;
    } else {
        if (children[key[start]-'a'] == nullptr) {
            // is_terminal = false;
            children[key[start]-'a'] = make_shared<TrieNode>();
            children[key[start]-'a']->insert(key, start+1);
        } else {
            ++num_subtrees;
            children[key[start]-'a']->insert(key, start+1);
        }
    }
}

bool Trie::TrieNode::in_trie(string key, size_t start) {
    if ((is_word && word == key) || (start == key.length()-1 && num_subtrees == 1 && children[key[start]-'a'] != nullptr)) return true;
    if (children[key[start]-'a'] == nullptr || start == key.length()-1) return false;
    return children[key[start]-'a']->in_trie(key, start+1);
}

Trie::Trie() {}

void Trie::insert(string key) {
    root->insert(key, 0);
}

bool Trie::in_trie(string key) {
    return root->in_trie(key, 0);
}
