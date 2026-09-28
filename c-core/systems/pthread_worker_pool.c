#include <stdio.h>
#include <stdlib.h>

typedef struct Task {
    void (*function)(void*);
    void *argument;
    struct Task *next;
} Task;
