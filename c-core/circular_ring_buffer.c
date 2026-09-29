/*
 * Circular Ring Buffer for Serial Streams
 */
#include <stdio.h>
#include <stdbool.h>

#define RING_CAPACITY 256

typedef struct {
    uint8_t buffer[RING_CAPACITY];
    size_t head;
    size_t tail;
    size_t count;
} RingBuffer;

bool ring_push(RingBuffer* rb, uint8_t byte) {
    if (rb->count >= RING_CAPACITY) return false;
    rb->buffer[rb->tail] = byte;
    rb->tail = (rb->tail + 1) % RING_CAPACITY;
    rb->count++;
    return true;
}

bool ring_pop(RingBuffer* rb, uint8_t* out) {
    if (rb->count == 0) return false;
    *out = rb->buffer[rb->head];
    rb->head = (rb->head + 1) % RING_CAPACITY;
    rb->count--;
    return true;
}
