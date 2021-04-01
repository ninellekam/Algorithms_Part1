#include <iostream>
#include <vector>

void urlencode(std::string& s) {
	const auto spaces_count = std::count(s.begin(), s.end(), ' ');

	int old_size = s.size();
	s.resize(s.size() + spaces_count * 2);
	std::cout << s.size();
	int write_pos = s.size() - 1;
	for (int i = old_size - 1; i >= 0; --i) {
		if (s[i] != ' ') {
			s[write_pos--] = s[i];
		}
		else {
			s[write_pos--] = '0';
			s[write_pos--] = '2';
			s[write_pos--] = '%';
		}
	}
	std::cout << s;
}

int main() {
	std::string s = "n i n a";
	urlencode(s);
}