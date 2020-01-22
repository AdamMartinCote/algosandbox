#ifndef HELLO_C_LINKEDLIST_H
#define HELLO_C_LINKEDLIST_H


#include <stdbool.h>
#include <stdlib.h>

struct Node {
    void *data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct LinkedList* make_linked_list() {
    struct LinkedList* ll = malloc(sizeof(struct LinkedList));
    ll->head = NULL;
    return ll;
};

void add_to_linked_list(struct LinkedList* ll, void* data) {
    if (!ll->head) {
        struct Node* node = malloc(sizeof(struct Node));
        ll->head = node;
        node->data = data;
    } else {
        struct Node* last = ll->head;
        while(last->next) last = last->next;
        last->next = malloc(sizeof(struct Node));
        last->next->data = data;
    }
}


#endif //HELLO_C_LINKEDLIST_H
