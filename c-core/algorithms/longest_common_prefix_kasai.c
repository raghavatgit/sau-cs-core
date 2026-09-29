#include <stdio.h>
#include <string.h>

void build_lcp(const char* txt, int* sa, int* lcp, int n) {
    int rank[n];
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) { k = 0; continue; }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && txt[i + k] == txt[j + k]) k++;
        lcp[rank[i]] = k;
        if (k > 0) k--;
    }
}
