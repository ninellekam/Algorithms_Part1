#include <iostream>
#include <algorithm>
#include <vector>


struct Prefix {
	int sum;
	int index;
};

bool comparator(Prefix a, Prefix b) {
	return a.sum < b.sum;
}

template <typename T>
std::pair<int, int> findSubArray(const std::vector<T> &arr, int n) {
	int start, end, min_diff = INT_MAX;
	Prefix pre_sum[n + 1];
	pre_sum[0].sum = 0;
	pre_sum[0].index = -1;
	for (int i = 1; i <= n; i++) {
		pre_sum[i].sum = abs(pre_sum[i - 1].sum + arr[i - 1]);
		pre_sum[i].index = i - 1;
	}
	sort(pre_sum, pre_sum + (n + 1), comparator);
	for (int i = 0; i < n + 1; i++)
		std::cout << pre_sum[i].sum << " " << std::endl;
	for (int i = 1; i <= n; i++) {
		int diff = pre_sum[i].sum - pre_sum[i - 1].sum;
		if (min_diff > diff) {
			min_diff = diff;
			start = pre_sum[i - 1].index;
			end = pre_sum[i].index;
		}
	}
	std::pair<int, int> p = std::make_pair(start + 1, end);
	return p;
}

int main() {
	std::vector<int> arr = { 2, 3, -6, -1, 6 };
	int n = arr.size();
	std::pair<int, int> point = findSubArray(arr, n);
	std::cout << point.first << " to " << point.second;
	return 0;
}