#include "Container.h"

void main() {
	setlocale(LC_ALL, "Russian");

	// �������� ����������
	Container container;
	// �������� ������� �� �����
	container.load("input.txt");

	std::cout << "� ������� " << container.size() << " ���������" << std::endl;
	// ����� �������
	container.printPage(1);
	
	std::cout << std::endl << "���������� 2 ������ �� ��������" << std::endl;
	container.setRowOnPage(2);
	container.printPage(1);

	system("pause");
}