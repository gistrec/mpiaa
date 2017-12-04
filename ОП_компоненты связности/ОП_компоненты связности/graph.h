#pragma once
#pragma once

#include <map>
#include <set>
#include <vector>

class Graph {

public:
	/// Добавить вершину
	void add_vertex(int vertex);

	/// Добавить ребро
	void add_edge(int start_vertex, int end_vertex);

	/// Получить все вершины в графе
	std::vector<int> get_vertices() const;

	/// Получить смежные вершины
	std::vector<int> get_adjacent_vertices(int src_vertex) const;

	/// Возвращает true, если в графе есть вершина
	bool has_vertex(int vertex) const;

	/// Возвращает true, если в графе есть ребро
	bool has_edge(int start_vertex, int end_vertex) const;

private:
	std::map<int, std::set<int>> vertices;
};