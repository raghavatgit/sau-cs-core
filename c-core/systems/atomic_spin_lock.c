#include <stdbool.h>

typedef struct {
    volatile int lock;
} SpinLock;

void spin_lock_init(SpinLock *sl) { sl->lock = 0; }
void spin_lock(SpinLock *sl) {
    while (__atomic_test_and_set(&sl->lock, __ATOMIC_ACQUIRE)) {
        #if defined(__x86_64__)
        __builtin_ia32_pause();
        #endif
    }
}
void spin_unlock(SpinLock *sl) {
    __atomic_clear(&sl->lock, __ATOMIC_RELEASE);
}
