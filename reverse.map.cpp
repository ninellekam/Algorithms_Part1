//Разверните массив!

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

std::vector<int> reverse_vec(std::vector<int> &vec) {
	size_t n = vec.size();

	for (int i = 0; i < n / 2; ++i) {
		int tmp = vec[i];
		vec[i] = vec[n - i - 1];
		vec[n - i - 1] = tmp;
	}
	for (auto it : vec)
		std::cout << it << " ";
	return vec;
}

int main() {
	std::vector<int> vec = {1, 1, 1, 0, 0, 12, 12, 12, 12, 0};
	reverse_vec(vec);
	// for (auto it : vec)
	// 	std::cout << it << " ";
	return 0;
}