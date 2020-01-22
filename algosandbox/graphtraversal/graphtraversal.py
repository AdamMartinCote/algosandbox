import logging
from typing import Generator

import networkx as nx


def dept_first_search(graph: nx.Graph, node=None) -> Generator:
    if node is None:
        try:
            node = list(graph.nodes[0])
        except Exception as e:
            logging.warning('empty graph in dept_first_search')
            logging.warning(e)
            return []
    stack = []
    visited = [node]
    stack.append(node)
    while stack:
        neighbors = graph.neighbors(stack[-1])
        new_neighbors = [n for n in neighbors if neighbors not in visited]
        stack += new_neighbors
        visited += new_neighbors
        yield stack.pop()
