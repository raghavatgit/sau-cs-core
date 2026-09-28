#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *buffer;
    size_t head;
    size_t tail;
    size_t max_size;
    bool full;
} RingBuffer;

RingBuffer* ring_buffer_init(size_t size) {
    RingBuffer *rb = (RingBuffer*)malloc(sizeof(RingBuffer));
    rb->buffer = (int*)malloc(size * sizeof(int));
    rb->head = 0;
    rb->tail = 0;
    rb->max_size = size;
    rb->full = false;
    return rb;
}

void ring_buffer_push(RingBuffer *rb, int data) {
    rb->buffer[rb->head] = data;
    if (rb->full) {
        rb->tail = (rb->tail + 1) % rb->max_size;
    }
    rb->head = (rb->head + 1) % rb->max_size;
    rb->full = (rb->head == rb->tail);
}

bool ring_buffer_pop(RingBuffer *rb, int *data) {
    if (!rb->full && (rb->head == rb->tail)) {
        return false; // Empty
    }
    *data = rb->buffer[rb->tail];
    rb->full = false;
    rb->tail = (rb->tail + 1) % rb->max_size;
    return true;
}
