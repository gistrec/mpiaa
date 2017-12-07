#include "Container.h"
#include "heapSort.h"


void main() {
	setlocale(LC_ALL, "Russian");

	// �������� ����������
	Container container;
	// �������� ������� �� �����
	container.load("input.txt");

	// �������� �������	
	container.print();
	std::cout << std::endl << std::endl;
	// ��������� �� ��������
	heapSort(container.table, container.table.size());
	// ��� ��� �������� �������
	container.print();

	system("pause");
}