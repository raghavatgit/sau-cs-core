/*
 * 0/1 Knapsack with rolling 1D array
 */
#include <stdio.h>
#include <string.h>

int knapsack_01(int W, int wt[], int val[], int n) {
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            int candidate = val[i] + dp[w - wt[i]];
            if (candidate > dp[w]) dp[w] = candidate;
        }
    }
    return dp[W];
}
