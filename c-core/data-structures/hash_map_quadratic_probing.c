#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 1024

typedef struct {
    int key;
    int value;
    bool is_occupied;
    bool is_deleted;
} HashEntry;

typedef struct {
    HashEntry entries[TABLE_SIZE];
    size_t count;
} HashMap;

unsigned int hash(int key) {
    unsigned int x = (unsigned int)key;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % TABLE_SIZE;
}

void map_insert(HashMap *map, int key, int value) {
    unsigned int h = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        unsigned int idx = (h + i * i) % TABLE_SIZE;
        if (!map->entries[idx].is_occupied || map->entries[idx].is_deleted) {
            map->entries[idx].key = key;
            map->entries[idx].value = value;
            map->entries[idx].is_occupied = true;
            map->entries[idx].is_deleted = false;
            map->count++;
            return;
        }
        if (map->entries[idx].key == key) {
            map->entries[idx].value = value;
            return;
        }
    }
}
