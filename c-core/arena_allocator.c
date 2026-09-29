/*
 * Arena Memory Bump Allocator
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t* buffer;
    size_t capacity;
    size_t offset;
} MemoryArena;

MemoryArena arena_create(size_t bytes) {
    return (MemoryArena){
        .buffer = (uint8_t*)malloc(bytes),
        .capacity = bytes,
        .offset = 0
    };
}

void* arena_alloc(MemoryArena* arena, size_t size, size_t align) {
    uintptr_t curr = (uintptr_t)(arena->buffer + arena->offset);
    uintptr_t aligned = (curr + (align - 1)) & ~(align - 1);
    size_t new_offset = (aligned - (uintptr_t)arena->buffer) + size;
    if (new_offset > arena->capacity) return NULL;
    arena->offset = new_offset;
    return (void*)aligned;
}

void arena_reset(MemoryArena* arena) {
    arena->offset = 0;
}
