#pragma once
#include  "memory"

/**
* Binary tree node.
*/
template <class valueType>
class TreeNode {

public:
	valueType value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;

	TreeNode(valueType value) {
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};