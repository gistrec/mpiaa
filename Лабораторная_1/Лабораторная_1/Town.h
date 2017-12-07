#include <string>
#include <iostream>

class Town {
public:
	std::string name; // �������� ������
	
	std::string type; // ��� ������: ���� town, ���� village

	float latitude; // ������
	float longitude; // �������

	int population; // ����� �������

	// ������� ���������� ������
	// � ������ ���������� ���������� � ������
	std::string to_string() const{
		return name + "|" + type + "|" + std::to_string(latitude) + "|" 
			+ std::to_string(longitude) + "|" +  std::to_string(population);
	}

	// ������� ��� ��������� �������� �� ������ ����
	// name|type|latitude|longitude|population
	void from_string(char* str) {
		// �������� �� ��� ������ ��������
		name = strtok_s(str, "|", &str); ///TODO: V522 https://www.viva64.com/en/w/V522 There might be dereferencing of a potential null pointer 'strtok_s(str, "|", & str)'. Operator = of the string class expects a valid pointer.
		type = strtok_s(str, "|", &str); ///TODO: V522 https://www.viva64.com/en/w/V522 There might be dereferencing of a potential null pointer 'strtok_s(str, "|", & str)'. Operator = of the string class expects a valid pointer.
		// std::stof(char*) - ��������� ������ � float
		latitude = std::stof(strtok_s(str, "|", &str)); ///TODO: V522 https://www.viva64.com/en/w/V522 There might be dereferencing of a potential null pointer 'strtok_s(str, "|", & str)'.
		longitude = std::stof(strtok_s(str, "|", &str)); ///TODO: V522 https://www.viva64.com/en/w/V522 There might be dereferencing of a potential null pointer 'strtok_s(str, "|", & str)'.
		// atoi(char*) - ��������� ������ � int
		population = atoi(str);
		if (population < 0) std::cout << "��������� �� ����� ���� �������������" << std::endl;
	}
};