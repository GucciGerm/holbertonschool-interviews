#include "binary_trees.h"

/**
 * binary_tree_is_full - This function will check if bt is full
 * @tree: tree is a ptr to the root node of tree we're checking
 *
 * Return: if tree empty return NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	/* if no parent */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	/* recursively call for left and right children */
	if (tree->left != NULL && tree->right != NULL)
	{
		return (binary_tree_is_full(tree->left)
			&& binary_tree_is_full(tree->right));
	}
	/* if, if cases never met, return 0 */
	return (0);
}
