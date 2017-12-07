#include "Container.h"

void main() {
	setlocale(LC_ALL, "Russian");

	// Создание контейнера
	Container container;
	// Загрузка записей из файла
	container.load("input.txt");

	std::cout << std::endl <<  "В таблице " << container.size() << " элементов" << std::endl << std::endl;
	// Вывод страниц
	container.printPage(1);
	
	std::cout << std::endl << "Установили 2 записи на стринице" << std::endl << std::endl;
	container.setRowOnPage(2);
	container.printPage(1);

	system("pause");
}