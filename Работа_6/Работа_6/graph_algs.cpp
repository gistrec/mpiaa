#include "graph_algs.h"
#include <queue>

// ����� ����� � �������
// ����� ����� ������ �������� �� ������� ��� ���
bool find(std::vector<int> vector, int verticle) {
	for (auto elem = vector.begin(); elem != vector.end(); elem++) {
		if (*elem == verticle) return true;
	}
	return false;
}

// ������� ��� ������ ��������� �����������
std::vector<std::vector<int>> connected_components(const Graph &graph) {
	// ������ ���� ������ � �����
	std::vector<int> verticles = graph.get_vertices();

	// ���������� �������
	// ���� ������� ���� � ������� - ��� ��������
	// ������� ����� ������ �������� find(std::vector<int> vector, int verticle)
	std::vector<int> isRun;

	// ���������
	std::vector<std::vector<int>> result;

	// ��� ���� ������ � �����
	for (auto verticle = verticles.begin(); verticle != verticles.end(); verticle++) {
		// ���� ������� �� ��������
		if (!find(isRun, *verticle)) {
			// ������� ����� ���������� �����������
			std::vector<int> component;

			// ������� �������, ����� ����� ��� ���������� �����������
			std::queue<int> queue;

			// ��������� ������� ������� � �������
			queue.push(*verticle);

			// ���� ������� �� �����
			// P.S. �.�. ��� ���� ����� ���� ������, �������
			// ��������� � ��� �� ����. ����������� ��� � ������� *verticle
			while (!queue.empty()) {
				// ������� ������� �� �������
				int runVerticle = queue.back();
				queue.pop();
				// ��������� ������� � ���������� �����������
				component.push_back(runVerticle);
				// �������� ������� ������� ��� ����������
				isRun.push_back(runVerticle);
				// �������� ������� �������
				std::vector<int> adjacent_vertices = graph.get_adjacent_vertices(runVerticle);
				// ���� ������� �� �������� - ��������� �� � �������
				for (auto v = adjacent_vertices.begin(); v != adjacent_vertices.end(); v++) {
					if (!find(isRun, *v)) queue.push(*v);
				}
			}
			result.push_back(component);
		}
	}
	return result;
}

// ����� ���������� ����
std::vector<int> shortest_path(const Graph &graph, int start_vertex, int end_vertex) {

	std::vector<int> needGo;
	needGo.push_back(start_vertex);

	std::vector<int> result;
	return result;
}