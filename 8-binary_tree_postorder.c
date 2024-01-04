#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through binary tree using post-order traversal
 * @root: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 */
void binary_tree_postorder(const binary_tree_t *root, void (*func)(int))
{
	if (!(root) || !(func))
		return;

	binary_tree_postorder(root->left, func);
	binary_tree_postorder(root->right, func);
	func(root->n);
}
