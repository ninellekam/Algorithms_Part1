#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool compare(std::unordered_map<int, int> my_txt, std::unordered_map<int, int> my_path) {
	for (int i = 0; i < 256; i++) {
		if (my_path[i] != my_txt[i]) {
			std::cout << i << " ";
			return false;
		}
	}
	return true;
}

bool	permute_anagram(const std::string &txt, const std::string &path) {
	size_t N = txt.size();
	size_t M = path.size();
	std::unordered_map<int, int> my_txt;
	std::unordered_map<int, int> my_path;

	for (int i = 0; i < M; i++) {
		my_path[(int)path[i] - (int)'A']++;
		my_txt[(int)txt[i] - (int)'A']++;
	}

	for (int i = M; i < N; ++i) {
		if (compare(my_txt, my_path))
			return true;

		my_txt[(int)txt[i] - (int)'A']++;
		my_txt[(int)txt[i - M] - (int)'A']--;
	}
	if (compare(my_txt, my_path))
			return true;
	std::cout << "no";
	return false;
}

int main()
{
	const std::string txt = "BACDGABCDA";
	const std::string path = "ABCD";
	std::cout << permute_anagram(path, txt);
	return 0;
}