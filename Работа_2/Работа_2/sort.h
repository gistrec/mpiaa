#pragma once
#include <vector>

// Сортировка пузырьком
void bubbleSort(std::vector<int> &array) {
	if (array.size() == 0 || array.size() == 1) return;

	for (size_t i = 0; i < array.size() - 1; ++i) {
		for (size_t j = 0; j < array.size() - i - 1; ++j) {
			//std::cout << "i: " << i << ", j:" << j << std::endl;
			if (array[j] > array[j + 1])
				std::swap(array[j], array[j + 1]);
		}
	}
}