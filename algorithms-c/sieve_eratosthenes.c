/*
 * Bitwise Sieve of Eratosthenes
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_PRIME 1000000
static uint8_t composite_bits[MAX_PRIME / 8 + 1];

static inline void set_composite(int n) {
    composite_bits[n >> 3] |= (1 << (n & 7));
}

static inline int is_prime(int n) {
    return !(composite_bits[n >> 3] & (1 << (n & 7)));
}

void sieve(int limit) {
    memset(composite_bits, 0, sizeof(composite_bits));
    set_composite(0);
    set_composite(1);
    for (int p = 2; p * p <= limit; p++) {
        if (is_prime(p)) {
            for (int i = p * p; i <= limit; i += p) {
                set_composite(i);
            }
        }
    }
}
