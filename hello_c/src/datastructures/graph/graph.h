//
// Created by Annick on 2020-01-16.
//

#ifndef HELLO_C_GRAPH_H
#define HELLO_C_GRAPH_H

struct Graph {
    struct Node *nodes;
    struct Arc *edges;
};

/** \brief create a graph with n nodes and no edges
 *
 * @param n number of nodes
 * @return the graph
 */
struct Graph *new_graph(int n);

#endif //HELLO_C_GRAPH_H
