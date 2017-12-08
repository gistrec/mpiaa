#include "bruteforce.h"
#include "sha256.h"
#include <iostream>

void main() {
	std::vector<std::string> words;
	words = all_words(std::string("abc"), 3);
	for (auto &word : words) {
		std::cout << word << "|" << std::endl;;
	}

	system("pause");
}