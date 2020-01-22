//
// Created by Annick on 2020-01-13.
//

#include <stdio.h>

void print_array(int **arr, int y, int x) {
    printf("\n");
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}