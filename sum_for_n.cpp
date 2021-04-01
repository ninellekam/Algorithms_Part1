#include <iostream>
#include <vector>
#include <sstream>
#include <string>

template <typename T>
std::string to_string(T value) {
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}

void	lexi(std::vector<int> &vec) {
	std::vector<std::string> str;
	size_t n = vec.size();
	for (int i = 0; i < n; i++) {
		str.push_back(to_string(vec[i]));
	}
	sort(str.begin(), str.end());
	for (int i = 0; i < n; i++) {
		vec[i] = std::stoi(str[i]);
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int sums(std::vector<int> &vec, std::vector<int> &vec_tmp, int target, int q) {
	size_t n = vec.size();
	if (target == 0) {
		return 0;
	}
	if (target < 0)
		return -1;
	for (int i = q; i < n; ++i) {
		vec_tmp.push_back(vec[i]);
		sums(vec, vec_tmp, target - vec[i], q);
		vec_tmp.pop_back();
	}
	return 1;
}