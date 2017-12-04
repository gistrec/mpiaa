#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "sort.h"

TEST_CASE("Empty array") {
	std::vector<int> input = {};
	std::vector<int> expected = {};
	bubbleSort(input);
	CHECK(input == expected);
}

TEST_CASE("One element") {
	std::vector<int> input = { 1 };
	std::vector<int> expected = { 1 };
	bubbleSort(input);
	CHECK(input == expected);
}

TEST_CASE("Dual element") {
	std::vector<int> input = { 1, 1 };
	std::vector<int> expected = { 1, 1 };
	bubbleSort(input);
	CHECK(input == expected);
}

TEST_CASE("Many elements") {
	std::vector<int> input = { 1, 3, 2 , 8};
	std::vector<int> expected = { 1, 2, 3 , 8};
	// Результат будет записан на место входного массива
	bubbleSort(input);
	// Проверка результата и ожидаемого результата на равенство 
	CHECK(input == expected);
}