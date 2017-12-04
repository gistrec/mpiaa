#include "dict.h"
#include <iostream>
#include <vector>

// ������������� �������
Dictionary::Dictionary() {
	table.resize(max_size);
	// ��� ������� � ������� ����� nullptr
	for (auto iter = table.begin(); iter != table.end(); ++iter) {
		*iter = nullptr;
	}
}

void Dictionary::set(const std::string &key, const std::string &value) {
	// �������� ��� �����
	int hash = Dictionary::getHash(key);
	// ���� � ������� ��� ���� ������ ����
	if (Dictionary::get(key) != "") {
		// ������� �������� �������� � ��������� � �������� ������
		std::shared_ptr<HashNode> node = table.at(hash);
		while (node->key != key) {
			node = node->next;
		}
		node->value = value;
	// ���� ����� ���
	} else {
		// ������� ����� ��������� � ��������� � ������ ������
		now_size++;
		std::shared_ptr<HashNode> newNode = std::make_shared<HashNode>();
		newNode->key = key;
		newNode->value = value;
		newNode->next = table.at(hash);
		table.at(hash) = newNode;
	}
}

std::string Dictionary::get(const std::string &key) const {
	// �������� ���
	int hash = Dictionary::getHash(key);
	// ���� ���������� ������� � � ����� �������� ���� - �� ����� �����, ������� ����
	std::shared_ptr<HashNode> node = table.at(hash);
	while (node != nullptr && node->key != key) {
		node = node->next;
	}
	// ���� ������� �� ���������� - ���������� ������ ������
	if (node == nullptr) return "";
	// ����� - ��������
	return node->value;
}

int Dictionary::size() const {
	return now_size;
}

// ������� ��� ��������� ����
// ���������� int'���� �������� ���� ����� � ������
// � ��� ����� �������� �� ������� ���������� ����� �� ������������ ������ �������
int Dictionary::getHash(const std::string &string) const {
	int hash = 0;
	for (std::string::const_iterator iter = string.begin(); iter != string.end(); ++iter) {
		hash += (int)*iter;
	}
	return hash % max_size;
}
