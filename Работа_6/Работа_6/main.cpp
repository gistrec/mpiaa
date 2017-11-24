#include "graph_algs.h"
#include "iostream"

void main() {
	Graph graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_edge(0, 1);
	graph.add_edge(2, 3);

	std::vector<std::vector<int>> result = connected_components(graph);

	for (std::vector<std::vector<int>>::iterator iter = result.begin(); iter != result.end(); ++iter) {
		for (std::vector<int>::iterator innerIter = iter->begin(); innerIter != iter->end(); ++innerIter) {
			std::cout << *innerIter << " ";
		}
		std::cout << std::endl;
	}
	system("pause");
}