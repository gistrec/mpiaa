#pragma once
#include <vector>
#include <fstream>

#include "Town.h"

class Container {

private:
	// Записей на странице
	// При постраничном выводе
	int rowOnPage = 5;

public:
	// Вектор, состоит из классов Town
	std::vector<Town> table;
	
	// Добавить	элемент
	void add(const Town &data) {
		// Если такого города еще нет
		if (!find(data)) {
			table.push_back(data);
		} else {
			std::cout << "Город " << data.name << " уже есть в таблице" << std::endl;
		}
	}

	int size() {
		return table.size();
	}

	// Есть ли город с таким же названием в контейнере
	bool find(const Town &data) const{
		for (int i = 0; i < table.size(); i++) {
			if (table[i].name == data.name) return true;
		}
		return false;
	}

	// Напечатать все
	void print() const {
		for (int i = 0; i < table.size(); i++) {
			std::cout << table[i].to_string() << std::endl;
		}
	}

	// Установить кол-во записей на странице
	void setRowOnPage(int count) {
		rowOnPage = count;
	}

	// Напечатать выбранную страницу
	void printPage(int page) {
		int maxPage = ceil(table.size() / rowOnPage);
		std::cout << "Выведена страница " << page << " из " << maxPage << std::endl;
		for (int i = rowOnPage * page; i < rowOnPage * (page + 1); i++) {
			std::cout << table[i].to_string() << std::endl;
		}
	}

	void Container::load(const std::string &fileName) {
		std::ifstream input(fileName);

		char buffer[120];		
		while (!input.eof()) {
			input.getline(buffer, 120);
			Town newTown;
			newTown.from_string(buffer);
			add(newTown);
		}
	}
};