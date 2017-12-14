#pragma once
#include <iostream>

int lines;  // Кол-во линий
int lenght; // Максимальная длина строки

char** matrix; // Собственно двухмерный массив из символов

// Инициализация массива
// Создаем двухмерный массив в динамической памяти
// размера    lines x lenght
void createMatrix() {
	matrix = new char*[lines];
	for (int line = 0; line < lines; line++) {
		matrix[line] = new char[lenght];
		for (int symbol = 0; symbol < lenght; symbol++) {
			matrix[line][symbol] = '\0';
		}
	}
}

// Фигния для сейва матрицы
void saveMatrix() {
	FILE *output;
	fopen_s(&output, "Output.txt", "w"); // появится в папке с .exe файлом
	fprintf_s(output, "%d %d\n", lines, lenght);
	for (int line = 0; line < lines; line++) {
		for (int symbol = 0; symbol < lenght; symbol++) {
			fprintf_s(output, "%c", matrix[line][symbol]);
			if (matrix[line][symbol] == '\n') break;
		}
	}
}

// Загружаем мастрицу
bool loadMatrix() {
	FILE *input;
	fopen_s(&input, "Input.txt", "r"); // появится в папке с .exe файлом
	if (input == NULL) return 0;
	fscanf_s(input, "%d %d\n", &lines, &lenght);
	createMatrix();
	for (int line = 0; line < lines; line++) {
		for (int symbol = 0; symbol < lenght; symbol++) {
			fscanf_s(input, "%c", &matrix[line][symbol]);
			if (matrix[line][symbol] == '\n') break;
		}
	}
}

// Получание суммы всех четных элементов в строке
int getSum(int line) {
	int sum = 0;
	for (int symbol = 0; symbol < lenght; symbol++) {
		if (symbol % 2) sum += (int)matrix[line][symbol];
	}
	return sum;
}

void qsort(int left, int right) {
	int main = right; // Порядок опорного элемента в векторе

	int local_left = left;
	int local_right = right;

	while (local_left < local_right) {
		// сдвигаем левую границу пока элемент vector[loval_right] больше [опорного элемента]
		while ((getSum(local_left) <= getSum(main)) && (local_left < local_right))
			local_left++;

		if (local_right != local_left) {// если границы не сомкнулись
										// Если элемент [left] соседний с [main]
										// Свопаем их
			if (local_left + 1 == main) {
				std::swap(matrix[local_left], matrix[main]);
				// Иначе перемещаем элемент [right] на место разрешающего
			} else {
				std::swap(matrix[local_left], matrix[main - 1]);
				std::swap(matrix[main - 1], matrix[main]);
				main--;
			}
			// сдвигаем левую границу вправо
			local_right--;
		}

	}
	if (local_left != left) qsort(left, main - 1); // Левая часть
	if (local_right != right) qsort(main, right); // Правая часть 
}

int main() {
	loadMatrix();
	qsort(0, lines - 1);
	saveMatrix();
	system("pause");
}