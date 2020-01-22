#include <assert.h>
#include <stdio.h>

#include "linkedlist.h"

void test_make_list();

void test_list_add_1();

void test_list_add_2();

void test_list_size();

void test_is_empty_true();

void test_is_empty_false();

int main() {
    test_make_list();
    test_list_add_1();
    test_list_add_2();
//    test_list_size();
    test_is_empty_true();
    test_is_empty_false();
    puts("Done");
}

void test_make_list() {
    struct List *list = make_list();
    assert(list != NULL);
    assert(list->head == NULL);
}

void test_list_add_1() {
    struct List *list = make_list();
    int value = 42;
    list_add(list, &value);
    void *data = list_get_item(list, 0);
    assert(data);
    puts("`test_list_add_1` OK");
}

void test_list_add_2() {
    struct List *list = make_list();
    int values[] = {6, 7};
    list_add(list, &values[0]);
    list_add(list, &values[1]);
    void *data = list_get_item(list, 0);
    assert(data);
    puts("`test_list_add_2` OK");
}

void test_list_size() {
    struct List *list = make_list();
    int vals[] = {1, 5, 7};
//    for (int i = 0; i < sizeof(vals)/ sizeof(int) - 1; ++i) {
//        list_add(list, &vals[i]);
//    }
    int res = list_get_size(list);
    assert(res == 3);
    printf("`list_size` OK");
}

void test_is_empty_true() {
    struct List *list = make_list();
    assert(list_is_empty(list) == 1);
    puts("`list_is_emtpy` OK for true");
}

void test_is_empty_false() {
    struct List *list = make_list();
    int x = 37;
    list_add(list, &x);
    assert(list_is_empty(list) == false);
    puts("`list_is_emtpy` OK for false");
}