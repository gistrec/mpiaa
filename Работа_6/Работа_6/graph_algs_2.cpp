#include "graph_algs_2.h"
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
// Поиск в ширину
// Работает за O(n+m), где n - число вершин, m - число ребер
//
// Сам алгоритм можно понимать как процесс "поджигания" графа:
// на нулевом шаге поджигаем только вершину s. 
// На каждом следующем шаге огонь с каждой уже горящей вершины перекидывается на всех её соседей;
// Т.е. за одну итерацию алгоритма происходит расширение "кольца огня" в ширину на единицу (отсюда и название алгоритма).
std::vector<int> shortest_path(const Graph &graph, int start_vertex, int end_vertex) {
	// Список всех вершин в графе
	std::vector<int> verticles = graph.get_vertices();
	// Результат
	std::vector<int> path;

	// Обработка исключительных ситуаций
	// Когда размер графа меньше, чем порядок вершины
	if (verticles.size() < start_vertex || verticles.size() < end_vertex) return path;
	// И когда начало и конец - одинаковые вершины
	if (start_vertex == end_vertex) return {0, 0};

	// Массив 'предков', в котором для каждоый вершины храним номер вершины, по которой мы попали в эту вершину
	std::vector<int> parents(verticles.size());
	// Массив длин путей
	std::vector<int> distance(verticles.size());
	// Массив уже подожженых вершин
	std::vector<int> used(verticles.size());

	// Сюда помещаем вершины, которые будем обходить
	std::queue<int> queue; 

	queue.push(start_vertex); // Добавляем стартовую вершину в начало 

	used[start_vertex] = true;
	parents[start_vertex] = -1;

	while (!queue.empty()) {
		int verticle = queue.front();
		queue.pop();
		// Получаем смежные вершины
		std::vector<int> adjacent_vertices = graph.get_adjacent_vertices(verticle);

		for (std::vector<int>::iterator v = adjacent_vertices.begin(); v != adjacent_vertices.end(); ++v) {
			if (!used[*v]) {
				used[*v] = true;
				queue.push(*v);
				distance[*v] = distance[verticle] + 1;
				parents[*v] = verticle;
			}
		}
	}
 

	

	if (used[end_vertex]) {
		int v = end_vertex;
		while (v != -1) {
			path.push_back(v);
			//std::cout << v << " ";
			v = parents[v];
		}
	}
	std::reverse(path.begin(), path.end());

	// Вывод результата
	//for (std::vector<int>::iterator v = path.begin(); v != path.end(); ++v)
	//	std::cout << *v << " ";
	//std::cout << std::endl;

	return path;
}