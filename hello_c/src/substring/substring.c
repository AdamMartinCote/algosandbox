//
// Created by Annick on 2020-01-17.
//
#include <limits.h>
#include <string.h>
#include <math.h>

int find_fragment(char const *text, char const *fragment, int editing_distance, int *resulting_index) {
    size_t cols = strlen(text) + 1;
    size_t rows = strlen(fragment) + 1;

    int table[rows][cols];

    // set base cases
    for (int i = 0; i < rows; ++i) {
        table[i][0] = i; // if the text is empty we need 1 insertion by fragment character
    }
    for (int j = 0; j < cols; ++j) {
        table[0][j] = 0; // no editing needed if the fragment is empty
    }

    // build the table
    for (int row = 1; row < rows; ++row) {
        for (int col = 1; col < cols; ++col) {
            if (text[col - 1] == fragment[row - 1]) {
                table[row][col] = (int) fmin(table[row - 1][col - 1],
                                             fmin(1 + table[row - 1][col],
                                                  1 + table[row][col - 1]));
            } else {
                table[row][col] = (int) fmin(1 + table[row - 1][col - 1],
                                             fmin(1 + table[row - 1][col],
                                                  1 + table[row][col - 1]));
            }

            // return value if the fragment is close enough
            if (row == rows - 1 && table[row][col] <= editing_distance) {
                *resulting_index = col;
                return table[row][col];
            }
        }
    }

    return -1;
}
