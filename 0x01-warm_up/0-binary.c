#include "search_algos.h"

/**
 * print_digit - This helper function will print array contents with message
 * @array: is the pointer to the first element of the array to search in
 * @left: this is the left side of the array (start)
 * @right: this is the right side of the array (end)
 *
 * Return: void
 */

void print_digit(int *array, size_t left, size_t right)
{
	size_t idx = left;

	printf("Searching in array: ");
	while (idx < right)
	{
		printf("%d, ", array[idx]);
		idx++;
	}
	printf("%d\n", array[idx]);
}

/**
 * binary_search - This function will search for value in sorted array of
 * integers using the binary search algorithum
 * @array: is the pointer to the first element of the array to search in
 * @size: is the number of elements within the array
 * @value: is the value we are searching for
 *
 * Return: the index where the value in located
 */

int binary_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;
	size_t mid;

	if (array == NULL)
	{
		return (-1);
	}
	while (left <= right)
	{
		mid = ((left + right) / 2);
		print_digit(array, left, right);
		if (array[mid] < value)
		{
			left = (mid + 1);
		}
		else if (array[mid] > value)
		{
			right = (mid);
		}
		else
		{
			return (mid);
		}
	}
	return (-1);
}
