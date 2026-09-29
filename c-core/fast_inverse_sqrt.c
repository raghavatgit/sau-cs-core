/*
 * Fast Inverse Square Root Algorithm
 */
#include <stdio.h>
#include <stdint.h>

float fast_inv_sqrt(float number) {
    int32_t i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = *(int32_t*)&y;
    i  = 0x5f3759df - (i >> 1); // Magical bit-hack
    y  = *(float*)&i;
    y  = y * (threehalfs - (x2 * y * y)); // 1st Newton iteration
    return y;
}
