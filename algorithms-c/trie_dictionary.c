/*
 * Alphabet Trie Prefix Tree
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    bool is_end_of_word;
} TrieNode;

TrieNode* trie_create(void) {
    TrieNode* node = (TrieNode*)calloc(1, sizeof(TrieNode));
    return node;
}

void trie_insert(TrieNode* root, const char* key) {
    TrieNode* curr = root;
    for (int i = 0; key[i]; i++) {
        int idx = key[i] - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = trie_create();
        }
        curr = curr->children[idx];
    }
    curr->is_end_of_word = true;
}
