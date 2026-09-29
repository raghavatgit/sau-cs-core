#include <stdio.h>

typedef struct Node {
    int p, ch[2];
    int rev;
} Node;

Node lct[10000];

int is_root(int x) {
    return lct[lct[x].p].ch[0] != x && lct[lct[x].p].ch[1] != x;
}
