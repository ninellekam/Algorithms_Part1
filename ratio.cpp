// Есть два массива с числами (уникальными)
// нужно составить третий массив,
// такой что i-й элемент этого массива
// есть кол-во пересекающихся элементов среди первых i в
// данных двух массивах

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

template <typename T>
void ratio_two_vectors(const std::vector<T> &vec1, const std::vector<T> &vec2) {
	std::unordered_map<int, int> un_map;
	size_t n = vec1.size();

	if (vec1[0] == vec2[0])
		un_map[0] = 1;
	for (int i = 1; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (vec1[i] == vec2[j]) {
				if (j > i)
					un_map[j] += 1;
				else
					++cnt;
			}
		}
		if (cnt != 0)
			un_map[i] += cnt + un_map[i - 1];
		else
			un_map[i] += un_map[i - 1];
	}
	for(auto it = un_map.begin(); it != un_map.end(); ++it)
		std::cout << " index " << it->first << " " << it->second << " " << std::endl;
}

int main() {
	std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 9};
	std::vector<int> vec2 = {3, 2, 8, 7, 9, 5, 6, 15};
	ratio_two_vectors(vec1, vec2);
	std::cout << std::endl;

	std::vector<int> vec3 = {2, 7, 3, 4};
	std::vector<int> vec4 = {2, 7, 8, 3};
	ratio_two_vectors(vec3, vec4);
	return 0;
}