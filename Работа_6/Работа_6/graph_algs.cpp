#include "graph_algs.h"
#include <queue>

bool find(std::vector<int> vector, int need) {
	for (auto elem = vector.begin(); elem != vector.end(); elem++) {
		if (*elem == need) return true;
	}
	return false;
}

std::vector<std::vector<int>> connected_components(const Graph &graph) {
	std::vector<int> verticles = graph.get_vertices();

	std::vector<std::vector<int>> result;

	std::vector<int> isRun;
	std::queue<int> queue;

	queue.push(verticles.at(0));

	// Дле всех вершин в очереди
	for (auto v = verticles.begin(); v != verticles.end(); v++) {
		std::vector<int> component;
		while (queue.size() != 0) {
			// Вершина, которую будем обрабатывать
			int verticle = queue.front();
			queue.pop();
			// Если вершина пройдена
			if (find(isRun, verticle)) continue;
			component.push_back(verticle);
			isRun.push_back(verticle);

			std::vector<int> adjacent = graph.get_adjacent_vertices(verticle);
			for (auto elem = adjacent.begin(); elem != adjacent.end(); elem++) {
				queue.push(*elem);
			}
		}
		if (!component.empty()) result.push_back(component);
	}

	return result;
}

// Найти кратчайший путь
std::vector<int> shortest_path(const Graph &graph, int start_vertex, int end_vertex) {

	std::vector<int> needGo;
	needGo.push_back(start_vertex);

	std::vector<int> result;
	return result;
}