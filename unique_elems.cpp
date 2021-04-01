// дан отсортированный массив, нужно оставить в нем только уникальные элементы

#include <iostream>
#include <vector>
#include <set>

template <typename T>
std::vector<T>	unique(std::vector<T> &vec) {
	size_t n = vec.size(), uniq = 0;

	for (int i = 1; i < n; ++i) {
		if (vec[i] != vec[uniq]) {
			++uniq;
			vec[uniq] = vec[i];
		}
	}
	vec.erase(vec.begin() + uniq + 1, vec.end());
	return (vec);
}

int main() {
	std::vector<int> vec = {1, 1, 1, 2, 3, 3, 4, 5, 6, 6};
	std::vector<int> vec_tmp = unique(vec);
	for (auto it : vec_tmp)
		std::cout << it << std::endl;
}