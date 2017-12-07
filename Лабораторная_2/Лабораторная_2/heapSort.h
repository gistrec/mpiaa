#pragma once
#include <vector>
#include "Town.h"

// ������� "�����������" ����� ���� - ������������ ����
void siftDown(std::vector<Town> &array, int root, int bottom) {
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
				  // ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom)    // ���� �� � ��������� ����, 
			maxChild = root * 2;    // ���������� ����� �������
									// ����� ���������� ������� ������� �� ����
		else if (array[root * 2].name.compare(array[root * 2 + 1].name) > 0)
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// ���� ������� ������� ������ ������������� �������
		if (array[root].name.compare(array[maxChild].name) < 0) {
			Town temp = array[root]; // ������ �� �������
			array[root] = array[maxChild];
			array[maxChild] = temp;
			root = maxChild;
		} else // �����
			done = 1; // �������� ������������
	}
}
// ������� ���������� �� ����
void heapSort(std::vector<Town> &array, int array_size) {
	// ��������� ������ ��� ��������
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(array, i, array_size);
	// ���������� ����� �������� ��������� ��������
	for (int i = array_size - 1; i >= 1; i--) {
		Town temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		siftDown(array, 0, i - 1);
	}
}