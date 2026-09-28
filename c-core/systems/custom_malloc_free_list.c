#include <stdio.h>
#include <stddef.h>

#define POOL_SIZE 65536

static char memory_pool[POOL_SIZE];

typedef struct BlockHeader {
    size_t size;
    int is_free;
    struct BlockHeader *next;
} BlockHeader;

static BlockHeader *free_list = (BlockHeader*)memory_pool;

void init_allocator() {
    free_list->size = POOL_SIZE - sizeof(BlockHeader);
    free_list->is_free = 1;
    free_list->next = NULL;
}

void* my_malloc(size_t size) {
    BlockHeader *curr = free_list;
    while (curr) {
        if (curr->is_free && curr->size >= size) {
            curr->is_free = 0;
            return (void*)((char*)curr + sizeof(BlockHeader));
        }
        curr = curr->next;
    }
    return NULL;
}
