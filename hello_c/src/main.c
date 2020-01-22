#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "nchoosek/nchoosek.h"
#include "sparechange/spacechange.h"
#include "substring/substring.h"
#include "datastructures/linkedlist/linkedlist.h"

void n_choose_k_demo() {
    printf("Using Divide and conquer:\n");
    clock_t begin, end;
    begin = clock();
    for (int i = 9; i > 1; --i) {
        int n = 10;

        printf("n choose k with %d, %d : ", n, i);

        int ret = n_choose_k_divide_and_conquer(n, i);

        printf("%d\n", ret);
    }
    end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("total time=%lf\n", time_spent);

    printf("\nUsing dp:\n");
    begin = clock();
    for (int i = 9; i > 1; --i) {
        int n = 10;

        printf("n choose k with %d, %d : ", n, i);

//        int ret = n_choose_k_dp(n, i);
        int ret = n_choose_k_dp_optimized(n, i);

        printf("%d\n", ret);
    }
    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("total time=%lf\n", time_spent);
}

void spare_change_demo() {
    int ns[] = {5, 8, 10, 11, 43};
    int coins[] = {1, 3, 5};

    for (int i = 0; i < sizeof(ns) / sizeof(int); ++i) {
        int n = ns[i];
        int result = compute_spare_change(n, coins, sizeof(coins)/sizeof(coins[0]));
        printf("computing number of coins for n=%d\n", n);
        printf("res = %d\n\n", result);
    }
}

void spare_change_with_list_demo() {
    int ns[] = {5, 8, 10, 11, 43};
    int coins[] = {1, 3, 5};

    for (int i = 0; i < sizeof(ns) / sizeof(int); ++i) {
        int n = ns[i];
        int solution[n];
        int result = compute_spare_change_with_list(n, coins, sizeof(coins)/sizeof(coins[0]), solution);
        printf("computing number of coins for n=%d\n", n);
        printf("res = %d\n\n", result);
    }
}

int* get_solution_from_list(int *solution_list, int length) {
    size_t size = 1;
    int *ret = malloc(sizeof(int) * size);
    return NULL; // WIP
}

void find_fragment_demo() {
    char const *brand = "CGGATCAGTCC";
    char const *fragment = "GAGA";
    for (int k = 1; k < 4; ++k) {
        printf("\nSearching for the fragment %s in %s, with k=%d :\n", fragment, brand, k);

        int solution_index = -1;
        int result = find_fragment(brand, fragment, k, &solution_index);
        printf("result=%d with index=%d\n", result, solution_index);

        char sub_brand[strlen(brand)];
        if (solution_index) {
            strncpy(sub_brand, brand, solution_index);
            printf("the brand containing the substring is \"%s\"", sub_brand);
        }
    }
}
void test_list_add_2() {
    struct List *list = make_list();
    int values[] = {6, 7};
    list_add(list, &values[0]);
    list_add(list, &values[1]);
    void *data = list_get_item(list, 0);
//    assert(data);
    puts("`test_list_add_2` OK");
}

int main() {
//    n_choose_k_demo();
//    spare_change_demo();
//    find_fragment_demo();
    test_list_add_2();
    return EXIT_SUCCESS;
}