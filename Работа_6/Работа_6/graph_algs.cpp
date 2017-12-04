#include "graph_algs.h"
#include "graph_algs_2.h"

/// Should return true if graph is connected, false otherwise.
/// Null graph (with no vertices) is connected.
/// Singleton graph (with only one vertex) is connected.
bool is_connected(const Graph &graph) {
	if (connected_components(graph).size() > 1) return false;
	return true;
}

/// Should return true if there is a path from start to end vertex.
/// If start and end vertices are the same, path exists.
bool path_exists(const Graph &graph, int start_vertex, int end_vertex) {
	if (shortest_path(graph, start_vertex, end_vertex).empty()) return false;
	return true;
}