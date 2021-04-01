#include <iostream>
#include <condition_variable>
#include <future>
#include <vector>
#include <set>
#include <unordered_map>
#include <chrono>
#include <optional>
#include <regex>

struct Result{
	bool	isCompleted;
	size_t	length;
};

Result find_face(std::string_view str) {
	enum class State{
		eyes,
		nose,
		smile,
		sad,
		none
	};
	State state = State::none;
	size_t counter = 0;
	bool completed_face = false;

	for(int i = 0; i <= str.size(); i++) {
		bool completed_face = state == State::smile || state == State::sad;
		if (str[i] == ':')
			state = state == State::none  ? State::eyes : State::none;
		else if (str[i] == '-')
			state = state ==  State::eyes ? State::nose : State::none;
		else if (str[i] == ')')
			state = (state == State::smile || state == State::nose)  ? State::smile : State::none;
		else if (str[i] == '(')
			state = (state == State::sad || state == State::nose)  ? State::sad: State::none;
		else
			state = State::none;

		if (state != State::none)
			++counter;
		if (state == State::none)
			return {completed_face, counter};
	}
	return {completed_face, counter};
}

void	del_smiles(std::string &str) {
	std::string s_save = str;
	Result res;
	for(size_t i = 0 ; i < str.size(); i++) {
		res = find_face(str.substr(i));
		if (res.isCompleted == 1) {
			size_t len = res.length, idx = 0, j = i, offset = i + len;
			while (idx <= len) {
				while (offset + idx != str.size()) {
					str[j] = str[offset + idx];
					str[offset + idx] = ' ';
					++idx;
					++j;
				}
			}

			while (j < len && offset + idx == str.size()) {
					str[j] = ' ';
					++j;
			}
		}
	}
	std::cout << "F O R  S T R:\n" << s_save << "\nR E S U L T :\n" <<  str  << "\n";
	std::cout << "--------------------------------\n";
}


void	unit_test() {
	std::string str = "nina:-)))))))))kamkia:-((((privet:-((";
	del_smiles(str);
	// str = "nina:-)))))))))kamkia:-((((privet:-((!!!@#))";
	// del_smiles(str);
	// str = "nina:-)))))))))kamkia:-((((privet:-((!!!@#))";
	// del_smiles(str);
	// str = "HELLO:-)))))))))((((";
	// del_smiles(str);
}

int main()
{
	unit_test();
	return 0;
}
