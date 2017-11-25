#include "graph_algs.h"
#include <queue>
#include <stack>
#include <iostream>

// Поиск числа в векторе
// Нужна чтобы искать пройдена ли вершина или нет
bool find(std::vector<int> vector, int verticle) {
	for (auto elem = vector.begin(); elem != vector.end(); elem++) {
		if (*elem == verticle) return true;
	}
	return false;
}

// Функция для поиска компонент связанности
std::vector<std::vector<int>> connected_components(const Graph &graph) {
	// Список всех вершин в графе
	std::vector<int> verticles = graph.get_vertices();

	// Пройденные вершины
	// Если вершина есть в векторе - она пройдена
	// Вершину нужно искать функцией find(std::vector<int> vector, int verticle)
	std::vector<int> isRun;

	// Результат
	std::vector<std::vector<int>> result;

	// Дле всех вершин в графе
	for (auto verticle = verticles.begin(); verticle != verticles.end(); verticle++) {
		// Если вершина не пройдена
		if (!find(isRun, *verticle)) {
			// Создаем новую компоненту связанности
			std::vector<int> component;

			// Создаем очередь, чтобы найти все компоненты связанности
			std::queue<int> queue;

			// Добавляем текущую вершину в очередь
			queue.push(*verticle);

			// Пока очередь не пуста
			// P.S. Т.е. тут идет поиск всех вершин, которые
			// Находятся в той же комп. связанности где и вершина *verticle
			while (!queue.empty()) {
				// Достаем вершину из очереди
				int runVerticle = queue.back();
				queue.pop();
				// Добавляем вершину в компоненту связанности
				component.push_back(runVerticle);
				// Отмечаем текущую вершину как пройденную
				isRun.push_back(runVerticle);
				// Получаем смежные вершины
				std::vector<int> adjacent_vertices = graph.get_adjacent_vertices(runVerticle);
				// Если вершины не пройдены - добавляем их в очередь
				for (auto v = adjacent_vertices.begin(); v != adjacent_vertices.end(); v++) {
					if (!find(isRun, *v)) queue.push(*v);
				}
			}
			result.push_back(component);
		}
	}
	return result;
}

// Найти кратчайший путь
std::vector<int> shortest_path(const Graph &graph, int start_vertex, int end_vertex) {
	// Список всех вершин в графе
	std::vector<int> verticles = graph.get_vertices();

	std::vector<int> distance(verticles.size());

	std::queue<int> queue; // Сюда помещаем вершины, которые будем обходить
	int run = 1; // Шаг
	queue.push(start_vertex);

	std::vector<int> isRun;

	while (!queue.empty()) {
		int verticle = queue.back();
		queue.pop();
		std::vector<int> adjacent_vertices = graph.get_adjacent_vertices(verticle);
		for (auto v = adjacent_vertices.begin(); v != adjacent_vertices.end(); v++) {
			if (distance.at(*v) < run) {
				distance.at(*v) = run;
			}
		}
	}
 



	for (std::vector<int>::iterator iter = distance.begin(); iter != distance.end(); ++iter) {
			std::cout << *iter << " ";
	}
	std::cout << std::endl;






	return std::vector<int>(2);
}