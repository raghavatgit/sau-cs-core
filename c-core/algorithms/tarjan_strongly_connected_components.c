#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 100

int disc[MAX_V], low[MAX_V], stack[MAX_V];
bool in_stack[MAX_V];
int timer = 0, top = -1;

int min(int a, int b) { return (a < b) ? a : b; }
