/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:39:06 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/15 14:45:21 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	stack_to_array(t_stack *stack, int *arr, int size)
{
	t_stack_node	*node;
	int				i;

	node = stack->top;
	i = 0;
	while (i < size)
	{
		arr[i] = node->data;
		node = node->prev;
		i++;
	}
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

static void	quicksort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

void	get_pivot(t_stack *stack)
{
	int	*arr;
	int	size;
	int	small_pivot_idx;
	int	big_pivot_idx;
	int	range;

	size = stack_size(stack);
	if (is_stack_empty(stack) || size == 1)
		return ;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		exit(1);
	stack_to_array(stack, arr, size);
	quicksort(arr, 0, size - 1);
	range = size / 3;
	small_pivot_idx = range - 1;
	big_pivot_idx = range * 2 - 1;
	if (size % 3 == 2)
		big_pivot_idx++;
	stack->small_pivot = arr[small_pivot_idx];
	stack->big_pivot = arr[big_pivot_idx];
	free(arr);
}

int	get_median(t_stack *stack)
{
	int	*arr;
	int	size;
	int	median_pivot_idx;
	int	median;

	size = stack_size(stack);
	if (is_stack_empty(stack) || size == 1)
		return (-1);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		exit(1);
	stack_to_array(stack, arr, size);
	quicksort(arr, 0, size - 1);
	median_pivot_idx = size / 2;
	if (size % 2 == 0)
		median = (arr[median_pivot_idx - 1] + arr[median_pivot_idx]) / 2;
	else
		median = arr[median_pivot_idx];
	free(arr);
	return (median);
}
