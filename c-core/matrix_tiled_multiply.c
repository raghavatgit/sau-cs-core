/*
 * Cache-Tiled Matrix Multiplication
 * Minimizes CPU L1 data cache eviction
 */
#include <stdio.h>

#define TILE_SIZE 32

void matrix_mult_tiled(int n, const float A[n][n], const float B[n][n], float C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = 0.0f;

    for (int ti = 0; ti < n; ti += TILE_SIZE) {
        for (int tj = 0; tj < n; tj += TILE_SIZE) {
            for (int tk = 0; tk < n; tk += TILE_SIZE) {
                for (int i = ti; i < ti + TILE_SIZE && i < n; i++) {
                    for (int k = tk; k < tk + TILE_SIZE && k < n; k++) {
                        for (int j = tj; j < tj + TILE_SIZE && j < n; j++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}
