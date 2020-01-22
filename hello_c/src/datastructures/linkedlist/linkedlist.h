//
// Created by Annick on 2020-01-18.
//

#ifndef HELLO_C_LINKEDLIST_H
#define HELLO_C_LINKEDLIST_H

#include <stdbool.h>

struct List {
    struct Node *head;
};

struct List *make_list();

struct List *list_add(struct List *list, void const *data);

void *list_get_item(struct List *list, unsigned int index);

int list_get_size(struct List *list);

bool list_is_empty(struct List *list);

#endif //HELLO_C_LINKEDLIST_H
