// Reverse list!

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int val) : val(val), next(nullptr) {};
};

ListNode* reverse_list(ListNode *list) {
	ListNode *curr = list, *next = nullptr, *prev = nullptr;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

int main() {
	ListNode *node = new ListNode;
	ListNode *head = node;


	for (int i = 0; i < 10; i++) {
		node->val = i;
		node->next = new ListNode;
		node = node->next;
	}
	ListNode *new_node = reverse_list(head);
	while (new_node) {
		std::cout << new_node->val << " ";
		new_node = new_node->next;
	}
}