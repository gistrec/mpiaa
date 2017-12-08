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
	// Результат будет записан на место входного массива
	counting_sort(input);
	// Проверка результата и ожидаемого результата на равенство 
	CHECK(input == expected);
}

TEST_CASE("One negative number") {
	std::vector<int> input = { -1 };
	std::vector<int> expected = { -1 };
	// Результат будет записан на место входного массива
	counting_sort(input);
	// Проверка результата и ожидаемого результата на равенство 
	CHECK(input == expected);
}

TEST_CASE("A lot of negative number") {
	std::vector<int> input = { -4, -3, -1, -2, -5 };
	std::vector<int> expected = { -5, -4, -3, -2, -1 };
	// Результат будет записан на место входного массива
	counting_sort(input);
	// Проверка результата и ожидаемого результата на равенство 
	CHECK(input == expected);
}