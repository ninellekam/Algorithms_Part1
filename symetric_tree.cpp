// Является ли бинарное дерево симметричным

#include <iostream>

struct Tree {
	int val;
	Tree *left;
	Tree *right;
	Tree() : val(0), left(nullptr), right(nullptr) {}
	Tree(int x) : val(x), left(nullptr), right(nullptr) {}
	Tree(int x, Tree *left, Tree *right) : val(x), left(left), right(right) {}
};

bool symetric_tree(Tree *l, Tree *r) {
	if (l == nullptr && r == nullptr)
		return true;
	if (l && r && l->val == r->val)
		return (symetric_tree(l->left, r->right));
	else
		return false;
}

int main() {
	Tree *root = new Tree;
	for (int i = 0; i < 5; ++i) {
		root->val = i;
		root->left = new Tree;
		root->right = new Tree;
	}
	std::cout << symetric_tree(root->left, root->right);
}