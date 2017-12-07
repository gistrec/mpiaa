#pragma once
#include "Town.h"
#include <vector>

void qsort(std::vector<Town> &vector, int left, int right) {
	int main = right; // Порядок опорного элемента в векторе

	int local_left = left;
	int local_right = right;

	while (local_left < local_right) {

		// сдвигаем левую границу пока элемент vector[loval_right] больше [опорного элемента]
		while ((vector[local_left].population <= vector[main].population) && (local_left < local_right))
			local_left++;

		if (local_right != local_left) {// если границы не сомкнулись
										// Если элемент [left] соседний с [main]
										// Свопаем их
			if (local_left + 1 == main) {
				std::swap(vector[local_left], vector[main]);
				// Иначе перемещаем элемент [right] на место разрешающего
			} else {
				std::swap(vector[local_left], vector[main - 1]);
				std::swap(vector[main - 1], vector[main]);
				main--;
			}
			// сдвигаем левую границу вправо
			local_right--;
		}

	}
	// Левая часть
	if (local_left != left) qsort(vector, left, main - 1);
	// Правая часть 
	if (local_right != right) qsort(vector, main, right);
}