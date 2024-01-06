#include "binary_trees.h"

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: array sorted
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t array_size = 0;

	if (heap == NULL || size == NULL)
		return (NULL);

	/* Get the size of the array */
	array_size = binary_tree_size(heap);

	/* Allocate memory for the sorted array */
	sorted_array = malloc(sizeof(int) * array_size);
	if (sorted_array == NULL)
		return (NULL);

	/* Perform in-order traversal to extract elements into the array */
	heap_to_sorted_array_helper(heap, sorted_array, &array_size);

	/* Update the size parameter */
	*size = array_size;

	return (sorted_array);
}

/**
 * heap_to_sorted_array_helper - performs in-order traversal to extract elements
 * from a binary max heap into a sorted array
 *
 * @heap: pointer to the root node of the heap
 * @sorted_array: pointer to the sorted array
 * @index: pointer to the current index in the array
 */
void heap_to_sorted_array_helper(const heap_t *heap, int *sorted_array, size_t *index)
{
	if (heap == NULL)
		return;

	/* Traverse the left subtree */
	heap_to_sorted_array_helper(heap->left, sorted_array, index);

	/* Add the current node's value to the array */
	sorted_array[*index] = heap->n;
	(*index)++;

	/* Traverse the right subtree */
	heap_to_sorted_array_helper(heap->right, sorted_array, index);
}
