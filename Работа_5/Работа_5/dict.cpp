#include "dict.h"
#include <iostream>
#include <vector>

// Инициализация массива
Dictionary::Dictionary() {
	table.resize(max_size);
	// Все индексы в массиве равны nullptr
	for (auto iter = table.begin(); iter != table.end(); ++iter) {
		*iter = nullptr;
	}
}

void Dictionary::set(const std::string &key, const std::string &value) {
	// Получаем хэш ключа
	int hash = Dictionary::getHash(key);
	// Если в словаре уже есть данный ключ
	if (Dictionary::get(key) != "") {
		// Происто изменяем значение в структуре с заданным ключом
		std::shared_ptr<HashNode> node = table.at(hash);
		while (node->key != key) {
			node = node->next;
		}
		node->value = value;
	// Если ключа нет
	} else {
		// Создаем новую структуру и вставляем в начало списка
		now_size++;
		std::shared_ptr<HashNode> newNode = std::make_shared<HashNode>();
		newNode->key = key;
		newNode->value = value;
		newNode->next = table.at(hash);
		table.at(hash) = newNode;
	}
}

std::string Dictionary::get(const std::string &key) const {
	// Получаем хэш
	int hash = Dictionary::getHash(key);
	// Пока существует элемент и у этого элемента ключ - не равен ключу, который ищем
	std::shared_ptr<HashNode> node = table.at(hash);
	while (node != nullptr && node->key != key) {
		node = node->next;
	}
	// Если элемент не существует - возвращаем пустую строку
	if (node == nullptr) return "";
	// Иначе - значение
	return node->value;
}

int Dictionary::size() const {
	return now_size;
}

// Функция для получения хэша
// Складываем int'овые значения всех чисел в строке
// И хэш равен остатоку от деления полученого числа на максимальный размер таблицы
int Dictionary::getHash(const std::string &string) const {
	int hash = 0;
	for (std::string::const_iterator iter = string.begin(); iter != string.end(); ++iter) {
		hash += (int)*iter;
	}
	return hash % max_size;
}
