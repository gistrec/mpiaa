#pragma once
#include <vector>
#include <iostream>

struct Class {
	int value;
	Class(int value) {
		this->value = value;
	}
};

void printArray(std::vector<Class> &vector) {
	for (int i = 0; i < vector.size(); i++) {
		std::cout << vector[i].value << " ";
	}
	std::cout << std::endl;
}

void qsort(std::vector<Class> &vector, int left, int right) {
	
	int main = right; // Порядок опорного элемента в векторе

	int local_left = left;
	int local_right = right;

	while (local_left < local_right) {

		/*std::cout << "----------------- START --------------------------" << std::endl;
		std::cout << "Vector: "; printArray(vector);
		std::cout << "Left: " << local_left << std::endl;
		std::cout << "Right: " << local_right << std::endl << std::endl;*/

		// сдвигаем левую границу пока элемент vector[loval_right] больше [опорного элемента]
		while ((vector[local_left].value <= vector[main].value) && (local_left < local_right))
			local_left++; 

		if (local_right != local_left) {// если границы не сомкнулись
			// Если элемент [left] соседний с [main]
			// Свопаем их
			if (local_left + 1 == main) {
				std::swap(vector[local_left], vector[main]);
			// Иначе перемещаем элемент [right] на место разрешающего
			} else {
				std::swap(vector[local_left], vector[main-1]);
				std::swap(vector[main-1], vector[main]);
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

		/*std::cout << "Vector[local_left]: " << vector[local_left].value << std::endl;
		std::cout << "Main: " << vector[main].value << std::endl;
		if (vector[local_left].value > vector[main].value && (local_left + 1) != main) {
			std::cout << "Swap: " << vector[local_left].value << " to "<< vector[local_right - 1].value << std::endl;
			std::swap(vector[local_left], vector[local_right - 1]);
			std::cout << "Swap: " << vector[local_right - 1].value << " to " << vector[local_right].value << std::endl;
			std::swap(vector[local_right - 1], vector[local_right]);
			main--;
			local_right--;
		} else if ((local_left + 1) == main) {
			std::swap(vector[local_left], vector[main]);
			main++;
		}
		std::cout << "----------------- MIDDLE --------------------------" << std::endl;
		std::cout << "Vector: "; printArray(vector);
		std::cout << "Left: " << local_left << std::endl;
		std::cout << "Right: " << local_right << std::endl << std::endl;
		if (vector[local_left].value < vector[main].value) {
			local_left++;
		}
		std::cout << "----------------- END --------------------------" << std::endl;
		std::cout << "Vector: "; printArray(vector);
		std::cout << "Left: " << local_left << std::endl;
		std::cout << "Right: " << local_right << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << " ------------- END FUNCTION ---------- " << std::endl;
	std::cout << "NO Left: " << left << std::endl;
	std::cout << "NO Right: " << right << std::endl;
	if ((local_left + 2) != left) {

	}
	if ((local_right + 2) != right) {
		std::cout << "LOCAL LEFT" << std::endl;
		qsort(vector, local_left, right);
	}*/
}

int main() {
	std::vector<Class> vector;

	vector.push_back(Class(1));
	vector.push_back(Class(8));
	vector.push_back(Class(5));
	vector.push_back(Class(3));
	vector.push_back(Class(2));

	vector.push_back(Class(1));
	vector.push_back(Class(8));
	vector.push_back(Class(8));
	vector.push_back(Class(1));
	vector.push_back(Class(4));
	vector.push_back(Class(9));
	vector.push_back(Class(2));
	vector.push_back(Class(7));
	printArray(vector);
	std::cout << std::endl;
	qsort(vector, 0, vector.size() - 1);
	printArray(vector);
	system("pause");
}