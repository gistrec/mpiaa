#pragma once
#include <vector>

void printArray(std::vector<int> &array) {
	for (std::vector<int>::iterator iter = array.begin(); iter != array.end(); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

void counting_sort(std::vector<int> &vec) {
	if (vec.size() < 2) return;

	// Минимальное и максимальное значение
	int min = vec[0];
	int max = vec[0];

	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		if (*iter > max) max = *iter;
		if (*iter < min) min = *iter;
	}

	int delta = 0 - min;

	std::vector<int> fixVector(vec.size());
	int b = 0;
	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		fixVector[b] = *iter + delta;
		b++;
	}

	// Создаем вспомогательный массив
	std::vector<int> cnt(vec.size());

	// Заполняем вспомогательный массив нулями
	for (auto iter = cnt.begin(); iter != cnt.end(); ++iter) {
		*iter = 0;
	}
	for (auto iter = fixVector.begin(); iter != fixVector.end(); ++iter) {
		++cnt[*iter];
	}
	b = 0;

	for (size_t j = 0; j < cnt.size(); ++j) {
		for (size_t i = 0; i < cnt[j]; ++i) {
			vec[b] = j - delta;
			//std::cout << j << " ";
			++b;
		}
	}
}