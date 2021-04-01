#include <iostream>
#include <vector>

int sums(std::vector<int> &vec, std::vector<int> vec_tmp, int target, int q) {
	size_t n = vec.size();
	if (target == 0)
		return 0;
	if (target < 0)
		return -1;
	for (int i = q; i < n; ++i) {
		vec_tmp.push_back(vec[i]);
		sums(vec, vec_tmp, target - vec[i], q);
		vec_tmp.pop_back();
	}
	return 0;
}