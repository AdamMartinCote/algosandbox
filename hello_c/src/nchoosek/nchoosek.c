#include <stdlib.h>

int min2(int x, int y) {
    return (x < y) ? x : y;
}

int n_choose_k_divide_and_conquer(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return n_choose_k_divide_and_conquer(n - 1, k) +
           n_choose_k_divide_and_conquer(n - 1, k - 1);
}

int n_choose_k_dp(int n, int k) {
    int **arr = calloc(sizeof(int *), (n + 1));
    for (int i = 0; i <= n; ++i) {
        arr[i] = calloc(sizeof(int), (k + 1));
    }
    // base case
    for (int i = 0; i < n; ++i) {
        /** the arr[n][n] base case is not necessary with tight bounds */
        arr[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min2(k, i); ++j) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    return arr[n][k];
}

int n_choose_k_dp_optimized(int n, int k) {
    int *arr = calloc(sizeof(int), k + 1);

    // base case
    arr[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = min2(k, i); j > 0; --j) {
            arr[j] = arr[j] + arr[j - 1];
        }
    }
    return arr[k];
}