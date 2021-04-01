#include <iostream>

struct shared_counter {
	int *obj = nullptr;
	size_t ref_cnt = 0;
};

class my_shared_ptr {
	public:
	my_shared_ptr(int *obj) {
		counter = new shared_counter;
		counter->obj = obj;
		++counter->ref_cnt;
	}
	my_shared_ptr(const my_shared_ptr& other) {
		counter = other.counter;
		++counter->ref_cnt;
	}
	~my_shared_ptr() {
		--counter->ref_cnt;
		if (counter->ref_cnt == 0) {
			delete counter->obj;
			delete counter;
		}
	}
	private:
		shared_counter *counter = nullptr;
};