#include "iostream"
#include "graph.h"
#include "queue"

using namespace std;

// ����� ����� � �������
// ����� ����� ������ �������� �� ������� ��� ���
bool find(vector<int> vector, int verticle) {
	for (auto elem = vector.begin(); elem != vector.end(); elem++) {
		if (*elem == verticle) return true;
	}
	return false;
}

// ������� ��� ������ ��������� �����������
vector<vector<int>> connected_components(const Graph &graph) {
	// ������ ���� ������ � �����
	vector<int> verticles = graph.get_vertices();

	// ���������� �������
	// ���� ������� ���� � ������� - ��� ��������
	// ������� ����� ������ �������� find(vector<int> vector, int verticle)
	vector<int> isRun;

	// ���������
	vector<vector<int>> result;

	// ��� ���� ������ � �����
	for (auto verticle = verticles.begin(); verticle != verticles.end(); verticle++) {
		// ���� ������� �� ��������
		if (!find(isRun, *verticle)) {
			// ������� ����� ���������� �����������
			vector<int> component;

			// ������� �������, ����� ����� ��� ���������� �����������
			vector<int> queue;

			// ��������� ������� ������� � �������
			queue.push_back(*verticle);

			// ���� ������� �� �����
			// P.S. �.�. ��� ���� ����� ���� ������, �������
			// ��������� � ��� �� ����. ����������� ��� � ������� *verticle
			while (!queue.empty()) {
				// ������� ������� �� �������
				int runVerticle = queue.back();
				queue.pop_back();
				// ��������� ������� � ���������� �����������
				component.push_back(runVerticle);
				// �������� ������� ������� ��� ����������
				isRun.push_back(runVerticle);
				// �������� ������� �������
				vector<int> adjacent_vertices = graph.get_adjacent_vertices(runVerticle);
				// ���� ������� �� �������� - ��������� �� � �������
				for (auto v = adjacent_vertices.begin(); v != adjacent_vertices.end(); v++) {
					if (!find(isRun, *v)) queue.push_back(*v);
				}
			}
			result.push_back(component);
		}
	}
	return result;
}


void main() {
	Graph graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_edge(0, 1);
	graph.add_edge(2, 3);

	vector<vector<int>> result = connected_components(graph);

	for (vector<vector<int>>::iterator iter = result.begin(); iter != result.end(); ++iter) {
		for (vector<int>::iterator innerIter = iter->begin(); innerIter != iter->end(); ++innerIter) {
			cout << *innerIter << " ";
		}
		cout << endl;
	}
	system("pause");
}