#include <iostream>
#include <algorithm>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
	ListNode* findNthFromEnd(ListNode* head, int n) {
	ListNode *last = nullptr, *cur = head;
	int pos = 1;
	while (cur->next) {
		pos++;
		cur = cur->next;
		if (pos > n) {
			last = last ? last->next : head;
		}
	}
	if (last) {
		std::cout << "The last N elem is " << last->val << std::endl;
		return last;
	}
	else
		return nullptr;
	}
};

int main() {
	ListNode *list = new ListNode;
	ListNode *head;
	size_t N = 15;
	head = list;
	for (int i = 0; i < N; ++i) {
		list->val = i;
		list->next = new ListNode;
		list = list->next;
	}
	list = head;
	Solution class_to_find;
	class_to_find.findNthFromEnd(list, 16);
}