#pragma once
#include <vector>

void printArray(std::vector<int> &array) {
	for (std::vector<int>::iterator iter = array.begin(); iter != array.end(); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

void counting_sort(std::vector<int> &vec) {
	// —оздаем вспомогательный массив
	
	// ћинимальное и максимальное значение
	int min = (int) std::min_element(vec.begin(), vec.end());


	std::vector<int> cnt(vec.size());
	// «аполн€ем вспомогательный массив нул€ми
	for (auto iter = cnt.begin(); iter != cnt.end(); ++iter) {
		*iter = 0;
	}
	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		++cnt[*iter];
	}
	int b = 0;

	for (size_t j = 0; j < cnt.size(); ++j) {
		for (size_t i = 0; i < cnt[j]; ++i) {
			vec[b] = j;
			//std::cout << j << " ";
			++b;
		}
	}
}