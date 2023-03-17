/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_greedy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:21:19 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/16 10:29:18 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	get_index_of_number(t_stack *stack, int number)
{
	t_stack_node	*dummy;
	size_t			count;

	if (stack == NULL || stack->top == NULL)
		return (0);
	dummy = stack->top;
	count = 0;
	while (dummy && dummy->data < number)
	{
		dummy = dummy->prev;
		count++;
	}
	return (count);
}

static void	small_numbers_to_down(t_stack *stack, int number)
{
	size_t	ra_count;
	size_t	rra_count;
	size_t	size;

	ra_count = get_index_of_number(stack, number);
	size = stack_size(stack);
	rra_count = size - ra_count;
	if (ra_count <= rra_count)
	{
		while (ra_count > 0)
		{
			ra(stack);
			ra_count--;
		}
	}
	else
	{
		while (rra_count > 0)
		{
			rra(stack);
			rra_count--;
		}
	}
}

static void	big_numbers_to_up(t_stack *stack_a, int number)
{
	while (is_biggest_num(stack_a, stack_a->head->data) == FALSE \
	&& stack_a->head && stack_a->head->data > number)
		rra(stack_a);
}

static void	sort_stack_a(t_stack *stack_a, int number)
{
	if (stack_a == NULL || stack_a->top == NULL)
		return ;
	if (is_biggest_num(stack_a, number) == TRUE)
	{
		min_to_top(stack_a);
		return ;
	}
	sort_one_two_three(stack_a);
	small_numbers_to_down(stack_a, number);
	big_numbers_to_up(stack_a, number);
}

void	apply_greedy(t_stack *stack_a, t_stack *stack_b)
{
	size_t	index;

	index = 0;
	if (sort_a(stack_a, stack_b) == COMPLETE && is_stack_empty(stack_b) == TRUE)
		return ;
	while (!is_stack_empty(stack_b))
	{
		index = get_min_cost_index(stack_a, stack_b);
		if (index * 2 <= stack_size(stack_b))
			cheapest_to_top_b(stack_b, index, RB);
		else
			cheapest_to_top_b(stack_b, stack_size(stack_b) - index, RRB);
		sort_stack_a(stack_a, stack_b->top->data);
		pa(stack_a, stack_b);
		if (is_biggest_num(stack_a, stack_a->top->data) == TRUE)
			ra(stack_a);
	}
	min_to_top(stack_a);
}
