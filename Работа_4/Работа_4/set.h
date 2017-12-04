#pragma once
#include "TreeNode.h"

/**
* Set of integer numbers.
*/
class Set {

public:
	/// Insert item into the set.
	void insert(int item);

	/// Check if item is in the set.
	bool find(int item) const;

	/// Get size of the set.
	int size() const;

private:
	std::shared_ptr<TreeNode<int>> root = nullptr;
};
