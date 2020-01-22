//
// Created by Annick on 2020-01-16.
//

#include <stdlib.h>
#include "graph.h"

static const int DEFAULT_NODE_NUMBER = 4;

struct Node {
    int id;
};

struct Edge {
    struct Node **head;
    struct Node **tail;
    int length;
};


struct Graph *new_graph(int n) {
    struct Graph* graph = malloc(sizeof(struct Graph));
//    struct Node* nodes[] = malloc(sizeof(struct Node) * n);
    graph->edges = NULL;
    graph->nodes = NULL;

}

void delete_graph(struct Graph* graph) {
    free(graph);
}
