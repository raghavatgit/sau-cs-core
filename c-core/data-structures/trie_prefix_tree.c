#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_end_of_word;
} TrieNode;

TrieNode* create_trie_node() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    node->is_end_of_word = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void trie_insert(TrieNode *root, const char *key) {
    TrieNode *curr = root;
    while (*key) {
        int idx = *key - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = create_trie_node();
        }
        curr = curr->children[idx];
        key++;
    }
    curr->is_end_of_word = true;
}

bool trie_search(TrieNode *root, const char *key) {
    TrieNode *curr = root;
    while (*key) {
        int idx = *key - 'a';
        if (!curr->children[idx]) return false;
        curr = curr->children[idx];
        key++;
    }
    return curr != NULL && curr->is_end_of_word;
}

bool trie_starts_with(TrieNode *root, const char *prefix) {
    TrieNode *curr = root;
    while (*prefix) {
        int idx = *prefix - 'a';
        if (!curr->children[idx]) return false;
        curr = curr->children[idx];
        prefix++;
    }
    return true;
}
