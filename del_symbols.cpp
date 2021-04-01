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
    bool isCompleted;
    size_t length;
};

//Лучше принимать std::strinv_view или const std::string&
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

//Название функции стоит поменять delete_faces, к примеру +  как ты принимаешь строчку? путем копирования, а не по ссылке
void	test(std::string &str) {
	std::string s_save = str;
	Result res;
	for(size_t i = 0 ; i < str.size(); i++) {
		res = find_face(str.substr(i)); //substr копирует вспомни про std::string_view, в случае вьюшки substr будет без копирования
		if (res.isCompleted == 1) {
			str.replace(i, res.length, ""); //Для первого раза окес, но Антон спросит какая сложность алгоритма в целом выходит
            //Он захочет увидеть вариант без использования replace, поскольку он дорогой
		}
	}
	std::cout << "FOR STR:\n" << s_save << "  RESULT\n" <<  str  << "\n";
	std::cout << "--------------------------------\n";
}


void	unit_test() {
	std::string str = "nina:-)))))))))kamkia:-((((privet:-((";
	test(str);
	str = "nina:-)))))))))kamkia:-((((privet:-((!!!@#))";
	test(str);
	str = "nina:-)))))))))kamkia:-((((privet:-((!!!@#))";
	test(str);
	str = "HELLO:-)))))))))((((";
	test(str);
}

int main()
{
	unit_test();
	return 0;
}
