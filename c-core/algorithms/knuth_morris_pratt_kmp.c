#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compute_lps(const char *pat, int m, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp_search(const char *pat, const char *txt) {
    int m = strlen(pat);
    int n = strlen(txt);
    int *lps = (int*)malloc(m * sizeof(int));
    compute_lps(pat, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    free(lps);
}
