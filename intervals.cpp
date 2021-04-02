#include <iostream>
#include <vector>
#include <string>
#include <map>

void	intervals(std::vector<int> &vec) {
	size_t N = vec.size();
	std::string s;
	int tmp;
	for (int i = 0; i < N - 1; ++i) {
		tmp = vec[i];
		while (vec[i + 1] - vec[i] == 1) {
			++i;
			if (vec[i + 1] - vec[i] != 1) {
				s += std::to_string(tmp);
				s += "-" +std::to_string(vec[i]);
				s += ",";
				++i;
				tmp = vec[i];
			}
		}
		s += std::to_string(tmp);
		if (i != N - 1)
			s += ",";
	}
	std::cout << s;
}

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 6, 7, 9, 22, 90, 91, 92, 100};
	intervals(vec);
}