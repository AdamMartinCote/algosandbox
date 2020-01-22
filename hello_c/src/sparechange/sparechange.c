//
// Created by Annick on 2020-01-14.
//

#include <stdlib.h>
#include <math.h>
#include <limits.h>

int compute_spare_change(int n, int const coin_values[], size_t coin_number) {
    int *tab = calloc(sizeof(int), n + 1);
    for (int i = 1; i <= n; ++i) { // skipping over index 0
        for (int j = 0; j < coin_number; ++j) {
            if (coin_values[j] == i) {
                tab[i] = 1;
                goto next;
            }
        }
        int minimal_combination = INT_MAX;
        for (int j = 1; j <= i / 2; ++j) {
            minimal_combination = (int) fmin(minimal_combination, tab[j] + tab[i - j]);
        }
        tab[i] = minimal_combination;
        next:
        continue;
    }
    return tab[n];
}

int compute_spare_change_with_list(const int n,
                                   int const coin_values[],
                                   size_t coin_number,
                                   int solution_list[]) {
    int *tab = calloc(sizeof(int), n + 1);
    solution_list = calloc(sizeof(int), n + 1);

    for (int i = 1; i <= n; ++i) { // skipping over index 0
        for (int j = 0; j < coin_number; ++j) {
            if (coin_values[j] == i) {
                tab[i] = 1;
                solution_list[i] = -i;
                goto next;
            }
        }
        int minimal_combination = INT_MAX;
        for (int j = 1; j <= i / 2; ++j) {
            int alternative = (int) fmin(minimal_combination, tab[j] + tab[i - j]);
            if (alternative < minimal_combination) {
                minimal_combination = alternative;
                solution_list[i] = j;
            }
        }
        tab[i] = minimal_combination;
        next:
        continue;
    }
    return tab[n];
}
