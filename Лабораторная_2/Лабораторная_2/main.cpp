#include "Container.h"
#include "heapSort.h"


void main() {
	setlocale(LC_ALL, "Russian");

	// Создание контейнера
	Container container;
	// Загрузка записей из файла
	container.load("input.txt");

	// Печатаем таблицу	
	container.print();
	std::cout << std::endl << std::endl;
	// Сортируем по названию
	heapSort(container.table, container.table.size());
	// Еще раз печатаем таблицу
	container.print();

	system("pause");
}