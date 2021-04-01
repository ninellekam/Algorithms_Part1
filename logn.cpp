// Есть массив из ноликов и единичек. начинается 0, заканчивается 1. Необходимо найти
// индекс, такой что a[i] = 0, a[i + 1] = 1 (За log n)
#include <iostream>
#include <vector>

template <typename T>
int	index(const std::vector<T> &vec) {
	size_t N = vec.size(), left = 0, right = vec.size() - 1, indx = 0;

	for (int i = 0; left < right; ++i) {
		size_t mid = (left + right) / 2;
		if (indx != N + 1 && vec[indx] == 0 && vec[indx + 1] == 1)
			return indx;
		if (vec[mid] == 1) {
			indx = mid;
			--right;
		}
		else if (vec[mid] == 0) {
			indx = mid;
			++left;
		}
	}
	return -1;
}

int main() {
	std::vector<int> vec = {0, 0, 1, 0, 0, 0, 1};
	std::cout << index(vec);
}