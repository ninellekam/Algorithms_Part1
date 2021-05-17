#include <iostream>
#include <vector>
#include <string>

int	shortest(std::string &s) {
	size_t n = s.size();
	int indx_x = -1, indx_y = -1, min_dist = INT_MAX;

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'X') {
			indx_x = i;
			std::cout << "x " << indx_x << " ";
		}
		if (s[i] == 'Y') {
			indx_y = i;
			std::cout << "y " << indx_y << " ";
		}
		if (indx_x != -1 && indx_y != -1) {
			int diff = abs(indx_y - indx_x);
			if (diff < min_dist)
				min_dist = diff;
		}
	}
	if (indx_x == -1 && indx_y == -1)
		return 0;
	return min_dist;
}

int main() {
	std::string s = "OOOXXXOOOOYYYYXY";
	std::cout << shortest(s);
}