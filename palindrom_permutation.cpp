// Существует ли перестановка введенной строки, которая является палиндромом

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool have_palindrom(const std::string &s) {
	std::unordered_map<int, int> char_counter;
	size_t n = s.size();
	size_t counter = 0;

	for (int i = 0; i < n; ++i) {
		++char_counter[s[i]];
	}
	for (int i = 0; i < 128; ++i)
		counter += char_counter[i] % 2;

	return counter <= 1;
}

int main() {
	const std::string s = "ninan";
	if (have_palindrom(s) == 1)
		std::cout << "yes";
}