#include "set.h"
#include <stack>
#include <iostream>

// Insert item into the set.
// If the item is in the set already, do nothing.
// To create new node: TreeNode *new_node = new TreeNode(item);
// To init tree: root = new_node;
// To insert new node: some_node->left = new_node; or some_node->right = new_node;
void Set::insert(int item) {
	std::shared_ptr<TreeNode<int>> newNode = std::make_shared<TreeNode<int>>(item);

	if (root == nullptr) {
		root = newNode;
		return;
	}

	std::shared_ptr<TreeNode<int>> node = root;
	while (true) {
		if (node->value == item) return;
		else if (node->value < item) {
			if (node->right != nullptr) node = node->right;
			else {
				node->right = newNode;
				return;
			}
		} else {
			if (node->left != nullptr) node = node->left;
			else {
				node->left = newNode;
				return;
			}
		}	
	}
}

// Return true if item is in the set, false otherwise.
bool Set::find(int item) const {
	std::shared_ptr<TreeNode<int>> node = root;
	while (node != nullptr) {
		// Если дерево пусто, сообщить, что узел не найден, и остановить
		if (node == nullptr) return false;
		if (node->value == item) return true;
		if (node->value < item) node = node->right;
		else node = node->left;
	}
	return false;
}

// Return size (number of items) of the set.
int Set::size() const {
	if (root == nullptr) return 0;
	std::stack<std::shared_ptr<TreeNode<int>>> stack;
	int count = 0;
	stack.push(root);
	//std::cout << "Node's: ";
	while (!stack.empty()) {
		count++;
		std::shared_ptr<TreeNode<int>> node = stack.top();
		stack.pop();
		//std::cout << node->value << " ";
		if (node->left != nullptr) stack.push(node->left);
		if (node->right != nullptr) stack.push(node->right);
	}
	//std::cout << std::endl;
	return count;
}
