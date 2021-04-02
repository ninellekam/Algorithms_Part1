#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

template <typename T>
std::string to_string(T value) {
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}

std::string create_compact_string_from_vector(std::vector<int> &vec)
{
	std::sort(vec.begin(), vec.end());
	std::string res;

	for (size_t i = 0; i < vec.size(); ++i)
	{
		res += std::to_string(vec[i]);

		size_t interval_index = i + 1;
		while (interval_index != vec.size() &&
			   (vec[interval_index - 1] == vec[interval_index] - 1 ||
				vec[interval_index - 1] == vec[interval_index]))
			++interval_index;
		if (--interval_index != i)
			res += "-" + std::to_string(vec[interval_index]);
		i = interval_index;

		if (i != vec.size() - 1)
			res += ",";
	}
	std::cout << res;
	return res;
}

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 6, 7, 9, 99, 123, 124, 125, 100};
	create_compact_string_from_vector(vec);
}