#include "trie.h"

using namespace std;

Trie::TrieNode::TrieNode() {
    for (int i = 0; i < 26; ++i) { children[i] = nullptr; }
}

void Trie::TrieNode::insert(string key, size_t start) {

    if (successor_index == -1) {
        successor_index = key[start]-'a';
    }
    is_terminal = false;

    if (start == key.length()-1) {
        shared_ptr<TrieNode> new_node = make_shared<TrieNode>();
        new_node->word = key;
        new_node->is_word = true;
        children[key[start]-'a'] = new_node;
    } else {
        if (children[key[start]-'a'] == nullptr) {
            children[key[start]-'a'] = make_shared<TrieNode>();
            children[key[start]-'a']->insert(key, start+1);
        } else {
            ++num_subtrees;
            is_terminal = false;
            children[key[start]-'a']->insert(key, start+1);
        }
    }
}

string Trie::TrieNode::end_of_branch() {
    if (is_terminal) return word;
    return children[successor_index]->end_of_branch();
}

string Trie::TrieNode::return_closest_match(string key, size_t start) {
    if ((is_word && word == key) || (start == key.length()-1 && num_subtrees == 1 && children[key[start]-'a'] != nullptr)) return children[key[start]-'a']->end_of_branch();
    if (children[key[start]-'a'] == nullptr || start == key.length()-1) return "NOT FOUND";
    return children[key[start]-'a']->return_closest_match(key, start+1);
}

Trie::Trie() {}

void Trie::insert(string key) {
    root->insert(key, 0);
}

string Trie::return_closest_match(string key) {
    return root->return_closest_match(key, 0);
}
