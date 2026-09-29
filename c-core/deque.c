/*
 * Double-Ended Queue (Deque)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* buffer;
    int head;
    int tail;
    int size;
    int capacity;
} Deque;

Deque deque_create(int capacity) {
    return (Deque){
        .buffer = (int*)malloc(capacity * sizeof(int)),
        .head = 0,
        .tail = 0,
        .size = 0,
        .capacity = capacity
    };
}
