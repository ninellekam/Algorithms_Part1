//Есть строка, нужно слова переставить в обратном порядке(пробелы между словами)

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

std::string denomo(std::string &input) {
	std::stack<std::string> s;
	size_t n = input.size();
	std::string output;
	int index = input.find(' ');

	while (index != -1) {
		s.push(input.substr(0, index));
		input = input.substr(index + 1, std::string::npos);
		index = input.find(' ');
	}
	s.push(input.substr(0, std::string::npos));

	while (!s.empty()) {
		output += s.top();
		if (output.size() != n)
			output += " ";
		s.pop();
	}
	return output;
}

int main() {
	std::string s = "nina kamkia hi hello op";
	std::cout << denomo(s);
	return 0;
}