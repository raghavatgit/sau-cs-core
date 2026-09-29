/*
 * Robin Hood Hashing Open-Addressing Hash Table
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint32_t key;
    uint32_t value;
    uint16_t dib; // Distance from initial bucket
    bool occupied;
} HashEntry;

static inline uint32_t hash32(uint32_t x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
