// Дан произвольный массив.
// Нужно найти индексы начала и конца любого подмассива
// с нулевой суммой
// если такого нет, то вернуть {-1, -1}
// (линия по памяти и времени)

#include <iostream>
#include <vector>
#include <unordered_map>

struct Prefix {
	int sum;
	int index;
};

bool comp(Prefix &a, Prefix &b) {
	return (a.sum < b.sum);
}

template <typename T>
std::pair<T, T> zero_sum(const std::vector<T> &vec) {
	size_t n = vec.size();
	Prefix map_sum[n + 1];
	map_sum[0].index = -1;
	map_sum[0].sum = 0;

	for(int i = 1; i <= n; i++) {
		map_sum[i].sum = map_sum[i - 1].sum + vec[i - 1];
		map_sum[i].index = i - 1;
	}
	std::sort(map_sum, map_sum + (n + 1), comp);
	for (int i = 1; i <= n; i++) {
		int diff = map_sum[i].sum - map_sum[i - 1].sum;
		if (diff == 0) {
			return std::make_pair(map_sum[i - 1].index + 1, map_sum[i].index);
		}
	}
	return std::make_pair(-1, -1);
}

int main() {
	std::vector<int> vec0 = {2, 3, 3, 3, 3, 3, 6, 0, 0, 8, -14};
	std::pair<int, int> pr = zero_sum(vec0);
	std::cout << "TEST-0 " << pr.first << " " << pr.second << std::endl;

	std::vector<int> vec1 = {3, -1, 0, 1, 2};
	std::pair<int, int> prr = zero_sum(vec1);
	std::cout << "TEST-1 " << prr.first << " " << prr.second << std::endl;

	std::vector<int> vec2 = {3, -1, 1, 1, 2};
	pr = zero_sum(vec2);
	std::cout << "TEST-2 " << pr.first << " " << pr.second << std::endl;

	std::vector<int> vec3 = {20, 30, 35, 15, 16, 17, 18, 19};
	pr = zero_sum(vec3);
	std::cout<< "TEST-3 " << pr.first << " " << pr.second << std::endl;

	std::vector<int> vec4 = {3, -1, 0, 1, 2};
	pr = zero_sum(vec4);
	std::cout << "TEST-4 " << pr.first << " " << pr.second << std::endl;

	std::vector<int> vec5 = {505,606, 707, 0, 1, 2, 303, 404};
	pr = zero_sum(vec5);
	std::cout << "TEST-5 " << pr.first << " " << pr.second << std::endl;
}