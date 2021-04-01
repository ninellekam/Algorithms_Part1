//Есть массив из чисел, нужно все не нолики влево, а все нолики вправо (линия)

#include <iostream>
#include <vector>

void	print_vec(const std::vector<int> &vec) {
	for (auto it : vec)
		std::cout << it << " ";
	return ;
}

template <typename T>
std::vector<T> zeroes_left_right(std::vector<T> &vec) {
	size_t n = vec.size(), indx = 0;
	for (int i = 0; i < n; ++i) {
		if (vec[i] != 0) {
			vec[indx] = vec[i];
			++indx;
		}
	}
	std::fill(vec.begin() + indx + 1, vec.end(), 0);
	return vec;
}

int main() {
	std::vector<int> vec = {10, 22, 50, 6, 0, 0, 0, 0, 0, 0, 0, 28, 29, 30, 40};
	zeroes_left_right(vec);
	print_vec(vec);
	std::cout << std::endl;

	std::vector<int> vec1 = {1, 3, 4, 0, 0, 0, 0, 8, 8, 8, 7, 10};
	zeroes_left_right(vec1);
	print_vec(vec1);

	std::vector<int> vec2 = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2, 2};
	zeroes_left_right(vec2);
	print_vec(vec2);
	std::cout << std::endl;
}