#include <stdio.h>
#include <string.h>

#define D 256
#define Q 101

void rabin_karp_search(const char *pat, const char *txt) {
    int m = strlen(pat);
    int n = strlen(txt);
    int p = 0, t = 0, h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * D) % Q;
    }

    for (int i = 0; i < m; i++) {
        p = (D * p + pat[i]) % Q;
        t = (D * t + txt[i]) % Q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) break;
            }
            if (j == m) printf("Pattern found at index %d\n", i);
        }
        if (i < n - m) {
            t = (D * (t - txt[i] * h) + txt[i + m]) % Q;
            if (t < 0) t += Q;
        }
    }
}
