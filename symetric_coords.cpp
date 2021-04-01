#include <iostream>
#include <vector>
#include <algorithm>

inline bool cmp_x (const std::pair<double , double>  &a, const std::pair<double , double> & b) {
	return a.first < b.first;
}

bool symetric_coords(std::vector<std::pair<double , double>> &vec) {
	size_t n = vec.size();
	sort(vec.begin(), vec.end(), cmp_x);
	auto max_x = std::max_element(vec.begin(), vec.end(), [](std::pair<double , double> &a,
						std::pair<double , double> &b) {return a.first < b.first;});
	auto min_x = std::max_element(vec.begin(), vec.end(), [](std::pair<double , double> &a,
						std::pair<double , double> &b) {return a.first > b.first;});
	double centre = (min_x->first + max_x->first) / 2;
	for (int i = 0; i < n; ++i) {
		if (vec[i].second != vec[n - i - 1].second)
			return false;
		if (((vec[i].first + vec[n - i - 1].first) / 2) != centre)
			return false;
	}
	std::cout << "\nSUCCES!";
	return true;
}

int main() {
	std::vector<std::pair<double , double>> vec = {{-2, 0}, {1, 0}, {2, 0}, {-1, 0}};
	std::cout << symetric_coords(vec);
}