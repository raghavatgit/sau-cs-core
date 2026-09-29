/*
 * High-Performance 64-Bit Word Bitset
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint64_t words[16]; // 1024 bits
} Bitset1024;

static inline void bitset_set(Bitset1024* b, int bit) {
    b->words[bit >> 6] |= (1ULL << (bit & 63));
}

static inline void bitset_clear(Bitset1024* b, int bit) {
    b->words[bit >> 6] &= ~(1ULL << (bit & 63));
}

static inline bool bitset_test(const Bitset1024* b, int bit) {
    return (b->words[bit >> 6] & (1ULL << (bit & 63))) != 0;
}
