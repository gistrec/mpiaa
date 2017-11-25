#include "iostream"
#include "graph.h"
#include "queue"

using namespace std;

// Поиск числа в векторе
// Нужна чтобы искать пройдена ли вершина или нет
bool find(vector<int> vector, int verticle) {
	for (auto elem = vector.begin(); elem != vector.end(); elem++) {
		if (*elem == verticle) return true;
	}
	return false;
}

// Функция для поиска компонент связанности
vector<vector<int>> connected_components(const Graph &graph) {
	// Список всех вершин в графе
	vector<int> verticles = graph.get_vertices();

	// Пройденные вершины
	// Если вершина есть в векторе - она пройдена
	// Вершину нужно искать функцией find(vector<int> vector, int verticle)
	vector<int> isRun;

	// Результат
	vector<vector<int>> result;

	// Дле всех вершин в графе
	for (auto verticle = verticles.begin(); verticle != verticles.end(); verticle++) {
		// Если вершина не пройдена
		if (!find(isRun, *verticle)) {
			// Создаем новую компоненту связанности
			vector<int> component;

			// Создаем очередь, чтобы найти все компоненты связанности
			vector<int> queue;

			// Добавляем текущую вершину в очередь
			queue.push_back(*verticle);

			// Пока очередь не пуста
			// P.S. Т.е. тут идет поиск всех вершин, которые
			// Находятся в той же комп. связанности где и вершина *verticle
			while (!queue.empty()) {
				// Достаем вершину из очереди
				int runVerticle = queue.back();
				queue.pop_back();
				// Добавляем вершину в компоненту связанности
				component.push_back(runVerticle);
				// Отмечаем текущую вершину как пройденную
				isRun.push_back(runVerticle);
				// Получаем смежные вершины
				vector<int> adjacent_vertices = graph.get_adjacent_vertices(runVerticle);
				// Если вершины не пройдены - добавляем их в очередь
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