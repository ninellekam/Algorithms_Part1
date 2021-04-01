//отсортировать вектор из 0 и 1 (иногда могут усложнить до вектора и 0, 1 и 2)

#include <iostream>
#include <vector>

template <typename T>
std::vector<T>	sort_0_1(std::vector<T> &vec) {
	size_t n = vec.size(), cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;

	for (int i = 0; i < n; ++i) {
		switch (vec[i]) {
			case 0:
				++cnt_0;
				break;
			case 1:
				++cnt_1;
				break;
			case 2:
				++cnt_2;
				break;
		}
	}
	size_t i = 0;
	while (cnt_0-- > 0)
		vec[i++] = 0;
	while (cnt_1-- > 0)
		vec[i++] = 1;
	while (cnt_2-- > 0)
		vec[i++] = 2;
	return (vec);
}

int main() {
	std::vector<int> vec = {0, 0, 1, 0, 0, 1, 0, 1, 1, 2, 0, 0, 2, 2, 1, 1};
	std::vector<int> vec_tmp = sort_0_1(vec);
	for (auto it : vec_tmp)
		std::cout << it << " ";
}