// Дан отсортированный массив,
// который циклически сдвинули на некоторое число
// элементов ( пример массива: [3, 1, 2])
// нужно найти число, на которое его сдвинули,
// за O(log N)!

#include <iostream>
#include <algorithm>
#include <vector>


template <typename T>
T index_of_cicle(std::vector<T> &vec) {
	int left = 0;
	int right = vec.size();
	int indx = -1;

	for (int i = 0; left < right; i++) {
		int mid = (left + right) / 2 + 1;
		if (vec[mid] < vec[left]) {
			indx = mid;
			right = --mid;
		}
		else {
			left = ++mid;
		}
	}
	return indx;
}

int main() {
	std::vector<int> vec1 = {3, 4, 5, 6, 7, 8, 9, 10, 11, -1, 0, 1, 2};
	std::cout << " TEST-1 " << index_of_cicle(vec1) << std::endl;

	std::vector<int> vec2 = {3, -1, 0, 1, 2};
	std::cout << " TEST-2 " << index_of_cicle(vec2) << std::endl;

	std::vector<int> vec3 = {20, 30, 35, 15, 16, 17, 18, 19};
	std::cout << " TEST-3 " << index_of_cicle(vec3) << std::endl;

	std::vector<int> vec4 = {3, -1, 0, 1, 2};
	std::cout << " TEST-4 " << index_of_cicle(vec4) << std::endl;

	std::vector<int> vec5 = {505,606, 707, 0, 1, 2, 303, 404};
	std::cout << " TEST-5 " << index_of_cicle(vec5) << std::endl;

	std::vector<int> vec6 = {900, 1023, -1, 0, 123, 223, 223, 323, 700};
	std::cout << " TEST-6 " << index_of_cicle(vec6) << std::endl;
}