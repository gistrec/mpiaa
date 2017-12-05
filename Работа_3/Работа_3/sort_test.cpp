#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "sort.h"

TEST_CASE("Empty array") {
	std::vector<int> input = {};
	std::vector<int> expected = {};
	counting_sort(input);
	CHECK(input == expected);
}

TEST_CASE("One element") {
	std::vector<int> input = { 0 };
	std::vector<int> expected = { 0 };
	counting_sort(input);
	CHECK(input == expected);
}

TEST_CASE("Dual element") {
	std::vector<int> input = { 0, 0 };
	std::vector<int> expected = { 0, 0 };
	counting_sort(input);
	CHECK(input == expected);
}

TEST_CASE("Many elements") {
	std::vector<int> input = { 1, 3, 0, 2 , 4 };
	std::vector<int> expected = { 0, 1, 2, 3 , 4 };
	// ��������� ����� ������� �� ����� �������� �������
	counting_sort(input);
	// �������� ���������� � ���������� ���������� �� ��������� 
	CHECK(input == expected);
}