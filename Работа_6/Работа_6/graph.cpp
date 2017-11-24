#include "graph.h"

void Graph::add_vertex(int vertex) {
	if (!has_vertex(vertex)) {
		vertices[vertex] = std::set<int>();
	}
}

void Graph::add_edge(int start_vertex, int end_vertex) {
	if (start_vertex != end_vertex) {
		vertices[start_vertex].insert(end_vertex);
		vertices[end_vertex].insert(start_vertex);
	} else {
		add_vertex(start_vertex);
	}
}

std::vector<int> Graph::get_vertices() const {
	std::vector<int> result;
	for (const auto &p : vertices) {
		result.push_back(p.first);
	}
	return result;
}

std::vector<int> Graph::get_adjacent_vertices(int src_vertex) const {
	const auto it = vertices.find(src_vertex);
	if (it == vertices.end()) {
		return std::vector<int>();
	}
	return std::vector<int>(it->second.begin(), it->second.end());
}

bool Graph::has_vertex(int vertex) const {
	return (vertices.find(vertex) != vertices.end());
}

bool Graph::has_edge(int start_vertex, int end_vertex) const {
	const auto it = vertices.find(start_vertex);
	if (it == vertices.end()) {
		return false;
	}
	return (it->second.find(end_vertex) != it->second.end());
}