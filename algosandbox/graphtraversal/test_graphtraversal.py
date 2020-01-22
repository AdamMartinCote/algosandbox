from unittest import TestCase

from networkx import nx

from graphtraversal.graphtraversal import dept_first_search


class Test(TestCase):
    def test_dept_first_search(self):
        graph = nx.Graph()
        graph.add_nodes_from([1, 2, 3])
        graph.add_edge(1, 2)
        graph.add_edge(2, 3)
        print(list(dept_first_search(graph)))
        self.fail()
