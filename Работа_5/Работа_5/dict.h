#pragma once

#include <memory>
#include <vector>
#include <string>
/**
* Dictionary that maps strings to strings.
*/
class Dictionary {
public:
	Dictionary();

	/// Set value for the key.
	/// Replace old value with the new one if the key already exists.
	void set(const std::string &key, const std::string &value);

	/// Get value for the key.
	/// Returns empty string if there is no such key.
	std::string get(const std::string &key) const;

	/// Get number of items (keys) in the dictionary.
	int size() const;

private:
	// Единица связанного списка
	struct HashNode {
		std::string key;
		std::string value;
		std::shared_ptr<HashNode> next;
	};

	// Максимальное кол-во записей в таблице
	int max_size = 3; // Целочисленный беззнаковый тип

	// Текущее кол-во записей в таблице
	int now_size = 0;

	// Массив из указателей на Единицу связанного списка
	// Массив расположен в динамике, т.к. мы будем менть длину
	std::vector<std::shared_ptr<HashNode>> table;

	// Возвращаем значение хэша от строки
	int getHash(const std::string &key) const;
};
