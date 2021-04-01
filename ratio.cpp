#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

template <typename T>
void ratio_two_vectors(const std::vector<T> &vec1, const std::vector<T> &vec2) {
	std::unordered_map<int, std::pair<double, int>> un_map;
	size_t n = vec1.size();

	if (vec1[0] == vec2[0]) {
		un_map[0].second = 1;
		un_map[0].first = 1;
	}
	for (int i = 1; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (vec1[i] == vec2[j]) {
				double counter = (double)un_map[i - 1].second / (double)(i + 1);
				un_map[i].first += (double)1 / (double)(i + 1) + counter ;
				++cnt;
			}
		}
		if (cnt != 0)
			un_map[i].second = cnt + un_map[i - 1].second;
		else {
			un_map[i].second = un_map[i - 1].second;
			un_map[i].first += (double)un_map[i - 1].second / (double)(i + 1);
		}
	}
	for(auto it = un_map.begin(); it != un_map.end(); ++it)
		std::cout << it->first << ": " << it->second.first << ", " << it->second.second << std::endl;
}

int main() {
	std::vector<int> vec1 = {1, 2, 3, 4};
	std::vector<int> vec2 = {3, 2, 8, 8};
	ratio_two_vectors(vec1, vec2);
	// std::vector<int> vec1 = {2, 2, 3, 4};
	// std::vector<int> vec2 = {2, 2, 8, 8};
	// ratio_two_vectors(vec1, vec2);
	return 0;
}