#include <iostream>
#include <condition_variable>
#include <future>
#include <vector>
#include <set>
#include <unordered_map>
#include <chrono>
#include <optional>
#include <regex>


// template <typename ValueType>
// struct NodeList
// {
//     ValueType data;
//     NodeList<ValueType> *next;

// };

class Complex
{
    double x;
    double y;

public:
    explicit Complex(double x, double y) : x(x), y(y) {}
    double get_x();
    double get_y() { return y; }
};

double Complex::get_x()
{
    return x;
}

void print_complex(Complex number)
{
    endl(std::cout << number.get_x() << " " << number.get_y());
}

class A
{
public:
    virtual void print_hi() = 0;
};

class B : public A
{
public:
    int x;
    int y;
    void print_hi() override {}
    void print_ok() {}
};

class C : public A
{
public:
    int x;
    int y;
    void print_hi() {}
};

// enum class EMove{
//     right,
//     left,
//     top,
//     down
// };

// template <typename ValueType>
// std::optional<size_t> binary_search(const std::vector<ValueType> &vec, const ValueType &target)
// {
//     if (vec.empty())
//         return std::nullopt;
//     size_t left = 0, right = vec.size();
//     while (left <= right)
//     {
//         size_t mid = (left + right) / 2;
//         if (vec[mid] < target)
//             left = ++mid;
//         else if (vec[mid] > target)
//             right = --mid;
//         else
//             return mid;
//     }
//     return std::nullopt;
// }


// auto delete_symbols(const std::string& message){
//     std::regex r(":-(\\(+|\\)+)");
//     return std::regex_replace(message, r, "");
// }

struct Result{
    bool isCompleted;
    size_t length;
};

Result find_face(std::string str) {
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

    for(char symbol : str) {
        bool completed_face = state == State::smile || state == State::sad;
        if (symbol == ':')
            state = state == State::none  ? State::eyes : State::none;
        else if (symbol == '-')
            state = state ==  State::eyes ? State::nose : State::none;
        else if (symbol == ')')
            state = (state == State::smile || state == State::nose)  ? State::smile : State::none;
        else if (symbol == '(')
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

int main()
{
    // std::vector<int> vec = {};
    // auto index = binary_search(vec, 7);
    // if(index)
    //     std::cout << "binary serach -- indx -- " <<  *index << std::endl;
    // auto res = find_face("dsafasdfsdfasdf      ");
    std::string str = "privet:-((";
   // std::string_view str_view(str);
	Result res;
    for(size_t i = 0 ; i < str.size(); i++) {
		res = find_face(str.substr(i));
		if (res.isCompleted == 1) {
			std::cout << "\n res.length  " << res.length << "\n";
			str.replace(i, res.length, "");
			std::cout << str  << "\n";
			// std::cout << res.length << std::endl;
			// std::cout << str.substr(i, res.length) << "\n";
		}
	}
    // int *a = new A();
    // std::optional<int> opt = std::nullopt;
    // opt = 5;
    // if(opt) std::cout << *opt << std::
    // Complex x = {1,2};
    // auto obj = 5.0;
    // auto obj2 = {1,2};
    // {1,2,3,4, 425123, 32451234};


    return 0;
}