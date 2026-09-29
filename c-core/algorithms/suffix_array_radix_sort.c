#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 50000

typedef struct {
    int index;
    int rank[2];
} Suffix;

int compare(const void* a, const void* b) {
    Suffix* s1 = (Suffix*)a;
    Suffix* s2 = (Suffix*)b;
    if (s1->rank[0] == s2->rank[0]) {
        return (s1->rank[1] < s2->rank[1]) ? -1 : 1;
    }
    return (s1->rank[0] < s2->rank[0]) ? -1 : 1;
}
