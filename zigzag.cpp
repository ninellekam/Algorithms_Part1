#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
void zigzag(const std::vector<T> &vec1, const std::vector<T> &vec2) {
	auto it1 = vec1.begin();
	auto it2 = vec2.begin();

	while (it1 != vec1.end()  && it2 != vec2.end()) {
		std::cout << *it1 << " " << *it2 << " ";
		++it1;
		++it2;
	}
	while(it1 != vec1.end()) {
		std::cout << *it1 << " ";
		++it1;
	}
	while(it2 != vec2.end()) {
		std::cout << *it2 << " ";
		++it2;
	}
}

int main() {
	std::vector<int> vec1 = {1, 2, 3};
	std::vector<int> vec2 = {4, 5, 6, 7, 8, 9};
	zigzag(vec1, vec2);
}