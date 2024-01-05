#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowes
 * @first: Pointer
 * @second: Pointer
 *
 * Return: Pointer
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	const binary_tree_t *fi_anc, *se_anc;

	for (fi_anc = first; fi_anc; fi_anc = fi_anc->parent)
		for (si_anc = second; si_anc; si_anc = si_anc->parent)
			if (fi_anc == si_anc)
				return ((binary_tree_t *)fi_anc);
	return (NULL);
}
