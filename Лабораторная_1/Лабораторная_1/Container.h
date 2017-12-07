#pragma once
#include <vector>
#include <fstream>

#include "Town.h"

class Container {
private:
	// ������, ������� �� ������� Town
	std::vector<Town> table;

	// ������� �� ��������
	// ��� ������������ ������
	int rowOnPage = 5;

public:
	
	// ��������	�������
	void add(const Town &data) {
		// ���� ������ ������ ��� ���
		if (!find(data)) {
			table.push_back(data);
		} else {
			std::cout << "����� " << data.name << " ��� ���� � �������" << std::endl;
		}
	}

	int size() {
		return table.size();
	}

	// ���� �� ����� � ����� �� ��������� � ����������
	bool find(const Town &data) const{
		for (int i = 0; i < table.size(); i++) {
			if (table[i].name == data.name) return true;
		}
		return false;
	}

	// ���������� ���
	void print() const {
		for (int i = 0; i < table.size(); i++) {
			std::cout << table[i].to_string() << std::endl;
		}
	}

	// ���������� ���-�� ������� �� ��������
	void setRowOnPage(int count) {
		rowOnPage = count;
	}

	// ���������� ��������� ��������
	void printPage(int page) {
		int maxPage = ceil(table.size() / rowOnPage);
		std::cout << "�������� �������� " << page << " �� " << maxPage << std::endl;
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