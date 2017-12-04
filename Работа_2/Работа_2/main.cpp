#include <iostream>
#include "sort.h"

// Функция для вывода массива на экран
void printArray(std::vector<int> &array) {
	std::cout << "Array: ";
	for (std::vector<int>::const_iterator iter = array.begin(); iter != array.end(); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

void mainA() {
	std::vector<int> array = { 2, 3, 4, 1, 0 };
	printArray(array);
	bubbleSort(array);
	printArray(array);
	system("pause");
}