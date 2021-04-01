// Дан массив отсортированный целых чисел, нужно найти сумму двух чисел массива
// максимально приближенную к наперёд заданному значению O(n)

#include <iostream>
#include <vector>

template <typename T>
int	predict_sum(std::vector<T> &vec, int sum) {
	size_t n = vec.size(), left = 0, right = vec.size() - 1;
	int min_diff = INT_MAX, min_sum = 0;
	for (int i = 0; left < right; ++i) {
		int sum_tmp = vec[left] + vec[right];
		int diff = abs(sum - sum_tmp);
		if (min_diff > diff) {
			min_diff = diff;
			min_sum = sum_tmp;
		}
		if (sum_tmp > sum)
			--right;
		else
			++left;
	}
	return min_sum;
}

int main() {
	std::vector<int> vec = {10, 22, 50, 6, 28, 29, 30, 40};
	std::cout << predict_sum(vec, 54) << std::endl;
	std::vector<int> vec1 = {1, 3, 4, 7, 10};
	std::cout << predict_sum(vec1, 15);
}