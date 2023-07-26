#include "sort.h"

/**
 * min_max - finds the minimum or maximum value
 * in an array
 * @array: search array
 * @size: size of array
 * @flag: indicator for min or max
 * Return: minimum value or maximum value
 */
int min_max(int *array, size_t size, int flag)
{
	int min = array[0], i, max = array[0];

	for (i = 1; i < (int)size; i++)
		if (array[i] < min)
			min = array[i];

	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	return (flag ? max : min);
}

/**
 * array_init - initializes an array
 * @index: index array
 * @count: count array
 * @max: maximum value in original array
 * Return: size of index and count array
 */
int array_init(int **index, int **count, int max)
{
	size_t i, j = 0;

	for (i = 0; (int)i <= max; i++, j++)
	{
		(*count)[j] = 0;
		(*index)[j] = i;
	}
	return (j);
}

/**
 * count_step - counts the number of each index
 * in array
 * @count: count array
 * @index_size: size of count array
 */
void count_step(int **count, int index_size)
{
	int k;

	for (k = 0; k < index_size; k++)
	{
		if (!k)
			(*count)[k] = (*count)[k];
		else
			(*count)[k] = (*count)[k] + (*count)[k - 1];
	}
}

/**
 * counting_sort - a function that sorts an
 * array using counting sort
 * @array: the address of the array
 * @size: the size of the array
 * Return: void
 **/
void counting_sort(int *array, size_t size)
{
	int max, array_range, num, *index, *count, *position;
	size_t i, j = 0, k, index_size;

	if (!array || size <= 1)
		return;

	max = min_max(array, size, 1);
	array_range = max + 1;

	index = malloc(sizeof(int) * array_range);
	count = malloc(sizeof(int) * array_range);
	position = malloc(sizeof(int) * size);
	if (!index || !count || !position)
		return;

	index_size = array_init(&index, &count, max);
	for (j = 0; j < size; j++)
	{
		num = array[j];
		for (k = 0; k < index_size; k++)
			if (num == index[k])
				count[k] += 1;
	}
	count_step(&count, index_size);
	print_array(count, index_size);
	for (j = 0; j < size; j++)
	{
		num = array[j];
		for (k = 0; k < index_size; k++)
		{
			if (num == index[k])
			{
				position[count[k] - 1] = num;
				count[k] -= 1;
			}
		}
	}
	for (i = 0; i < size; i++)
		array[i] = position[i];
	free(count), free(index), free(position);
}
