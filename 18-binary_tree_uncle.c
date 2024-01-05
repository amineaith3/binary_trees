#include "binary_trees.h"

/**
 * search_uncle - binary tree
 * @node: node
 * Return: uncle
 */
binary_tree_t *search_uncle(binary_tree_t *node)
{
	binary_tree_t *granddad = NULL;

	if (!node || !(node->parent))
		return (NULL);
	granddad = node->parent;
	/* check left or right uncle */
	if (granddad->left && (granddad->left != node))
		return (granddad->left);
	else if (granddad->right && (granddad->right != node))
		return (granddad->right);
	return (NULL);
}

/**
 * binary_tree_uncle - binary tree
 * @node: node
 * Return: uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);
	return (search_uncle(node->parent));
}
