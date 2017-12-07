#pragma once
#include <vector>
#include "Town.h"

// Функция "просеивания" через кучу - формирование кучи
void siftDown(std::vector<Town> &array, int root, int bottom) {
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
				  // Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom)    // если мы в последнем ряду, 
			maxChild = root * 2;    // запоминаем левый потомок
									// иначе запоминаем больший потомок из двух
		else if (array[root * 2].name.compare(array[root * 2 + 1].name) > 0)
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (array[root].name.compare(array[maxChild].name) < 0) {
			Town temp = array[root]; // меняем их местами
			array[root] = array[maxChild];
			array[maxChild] = temp;
			root = maxChild;
		} else // иначе
			done = 1; // пирамида сформирована
	}
}
// Функция сортировки на куче
void heapSort(std::vector<Town> &array, int array_size) {
	// Формируем нижний ряд пирамиды
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(array, i, array_size);
	// Просеиваем через пирамиду остальные элементы
	for (int i = array_size - 1; i >= 1; i--) {
		Town temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		siftDown(array, 0, i - 1);
	}
}