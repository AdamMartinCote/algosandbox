//
// Created by Annick on 2020-01-18.
//

#include <stdlib.h>
#include <stdbool.h>

#include "linkedlist.h"

struct Node {
    void *data;
    struct Node *next;
};

bool list_is_empty(struct List *list) {
    return !list->head;
}

struct List *make_list() {
    return calloc(1, sizeof(struct List));
}

struct List *list_add(struct List *list, void const *data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = (void *) data;

    struct Node *insert_point = list->head;
    if (!insert_point) {
        list->head = new_node;
        return list;
    }
    while (insert_point->next)
        insert_point = insert_point->next;
    insert_point->next = new_node;
    return list;
}

void *list_get_item(struct List *list, unsigned int index) {
    if (list_is_empty(list))
        return NULL;
    struct Node *iterator = list->head;
    int it_count = 0;
    while (it_count < index && iterator->next) {
        iterator = iterator->next;
        ++it_count;
    }
    if (index == it_count)
        return iterator->data;
    return NULL;
}


int list_get_size(struct List *list) {
    if (list_is_empty((list)))
        return 0;
    int count = 1;
    struct Node *it = list->head;
    while (it->next) {
        it = it->next;
        ++count;
    }
    return count;
}