#include <string>
#include <iostream>

class Town {
public:
	std::string name; // Название города
	
	std::string type; // Тип города: либо town, либо village

	float latitude; // Широта
	float longitude; // Долгота

	int population; // Число жителей

	// Функция возвращает строку
	// В которй содержится информация о городе
	std::string to_string() const{
		return name + "|" + type + "|" + std::to_string(latitude) + "|" 
			+ std::to_string(longitude) + "|" +  std::to_string(population);
	}

	// Функция для получения значений из строки вида
	// name|type|latitude|longitude|population
	void from_string(char* str) {
		// Вырезаем из нее нужные элементы
		name = strtok_s(str, "|", &str); ///TODO: V522 https://www.viva64.com/en/w/V522 There might be dereferencing of a potential null pointer 'strtok_s(str, "|", & str)'. Operator = of the string class expects a valid pointer.
		type = strtok_s(str, "|", &str); ///TODO: V522 https://www.viva64.com/en/w/V522 There might be dereferencing of a potential null pointer 'strtok_s(str, "|", & str)'. Operator = of the string class expects a valid pointer.
		// std::stof(char*) - переводит строку в float
		latitude = std::stof(strtok_s(str, "|", &str)); ///TODO: V522 https://www.viva64.com/en/w/V522 There might be dereferencing of a potential null pointer 'strtok_s(str, "|", & str)'.
		longitude = std::stof(strtok_s(str, "|", &str)); ///TODO: V522 https://www.viva64.com/en/w/V522 There might be dereferencing of a potential null pointer 'strtok_s(str, "|", & str)'.
		// atoi(char*) - переводит строку в int
		population = atoi(str);
		if (population < 0) std::cout << "Население не может быть отрицательным" << std::endl;
	}
};