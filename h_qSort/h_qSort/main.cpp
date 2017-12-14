#pragma once
#include <iostream>

int lines;  // ���-�� �����
int lenght; // ������������ ����� ������

char** matrix; // ���������� ���������� ������ �� ��������

// ������������� �������
// ������� ���������� ������ � ������������ ������
// �������    lines x lenght
void createMatrix() {
	matrix = new char*[lines];
	for (int line = 0; line < lines; line++) {
		matrix[line] = new char[lenght];
		for (int symbol = 0; symbol < lenght; symbol++) {
			matrix[line][symbol] = '\0';
		}
	}
}

// ������ ��� ����� �������
void saveMatrix() {
	FILE *output;
	fopen_s(&output, "Output.txt", "w"); // �������� � ����� � .exe ������
	fprintf_s(output, "%d %d\n", lines, lenght);
	for (int line = 0; line < lines; line++) {
		for (int symbol = 0; symbol < lenght; symbol++) {
			fprintf_s(output, "%c", matrix[line][symbol]);
			if (matrix[line][symbol] == '\n') break;
		}
	}
}

// ��������� ��������
bool loadMatrix() {
	FILE *input;
	fopen_s(&input, "Input.txt", "r"); // �������� � ����� � .exe ������
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

// ��������� ����� ���� ������ ��������� � ������
int getSum(int line) {
	int sum = 0;
	for (int symbol = 0; symbol < lenght; symbol++) {
		if (symbol % 2) sum += (int)matrix[line][symbol];
	}
	return sum;
}

void qsort(int left, int right) {
	int main = right; // ������� �������� �������� � �������

	int local_left = left;
	int local_right = right;

	while (local_left < local_right) {
		// �������� ����� ������� ���� ������� vector[loval_right] ������ [�������� ��������]
		while ((getSum(local_left) <= getSum(main)) && (local_left < local_right))
			local_left++;

		if (local_right != local_left) {// ���� ������� �� ����������
										// ���� ������� [left] �������� � [main]
										// ������� ��
			if (local_left + 1 == main) {
				std::swap(matrix[local_left], matrix[main]);
				// ����� ���������� ������� [right] �� ����� ������������
			} else {
				std::swap(matrix[local_left], matrix[main - 1]);
				std::swap(matrix[main - 1], matrix[main]);
				main--;
			}
			// �������� ����� ������� ������
			local_right--;
		}

	}
	if (local_left != left) qsort(left, main - 1); // ����� �����
	if (local_right != right) qsort(main, right); // ������ ����� 
}

int main() {
	loadMatrix();
	qsort(0, lines - 1);
	saveMatrix();
	system("pause");
}