#pragma once
#include "Town.h"
#include <vector>

void qsort(std::vector<Town> &vector, int left, int right) {
	int main = right; // ������� �������� �������� � �������

	int local_left = left;
	int local_right = right;

	while (local_left < local_right) {

		// �������� ����� ������� ���� ������� vector[loval_right] ������ [�������� ��������]
		while ((vector[local_left].population <= vector[main].population) && (local_left < local_right))
			local_left++;

		if (local_right != local_left) {// ���� ������� �� ����������
										// ���� ������� [left] �������� � [main]
										// ������� ��
			if (local_left + 1 == main) {
				std::swap(vector[local_left], vector[main]);
				// ����� ���������� ������� [right] �� ����� ������������
			} else {
				std::swap(vector[local_left], vector[main - 1]);
				std::swap(vector[main - 1], vector[main]);
				main--;
			}
			// �������� ����� ������� ������
			local_right--;
		}

	}
	// ����� �����
	if (local_left != left) qsort(vector, left, main - 1);
	// ������ ����� 
	if (local_right != right) qsort(vector, main, right);
}