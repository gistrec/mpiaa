#include "bruteforce.h"
#include "sha256.h"



// Return all possible words that can be created with symbols from alphabet.
// Alphabet - string of symbols, symbols are not repeated.
// Word's length - from 1 up to max length.
// Return empty array if there is no symbols or max length is less then 1.
std::vector<std::string> all_words(const std::string &alphabet, int max_length) {
	std::vector<std::string> all_words;
	for (int length = 1; length <= max_length; ++length) {
		
		// Создание для массив
		// Индекс элемента - равен индексу символа в строке
		// Значение элемента - равно индексу в алфавите
		std::vector<int> data(length);
		for (int &pos : data) pos = 0; // Обнуление

		std::string newWord;
		
		while (data[0] != alphabet.size()) {
			for (int symbol = 0; symbol < length; ++symbol) {
				newWord += alphabet[data[symbol]];
			}
			data[length-1]++;
			// Проверка массива 
			for (int i = 0; i < length; i++) {
				if (data[i] >= alphabet.length()) {
					if (i != 0) {
						data[i] = 0;
						data[i - 1]++;
						i = 0;
					} else data[0] == alphabet.size();
				}
			}
			all_words.push_back(newWord);
			newWord.erase();
		}
	}
	return all_words;
}

// Try to crack password by brute force, using all possible passwords with given alphabet and max length.
// Use sha256(string) function to compute password's hash and match it with given hash.
// Return password for which hashes are matched.
// Return empty string if password isn't found.
std::string bruteforce(const std::string &alphabet, int max_length, const std::string &password_hash) {
	std::vector<std::string> passwords = all_words(alphabet, max_length);
	for (std::string pass : passwords) {
		if (sha256(pass) == password_hash) return pass;
	}
	return "";
}
