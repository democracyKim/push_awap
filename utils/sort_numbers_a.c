/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:12:30 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/15 16:34:51 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three_numbers(t_stack *stack_a)
{
	int	pattern;

	pattern = pattern_three_numbers(stack_a);
	if (pattern == 1)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (pattern == 2)
		ra(stack_a);
	else if (pattern == 3)
		rra(stack_a);
	else if (pattern == 4)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (pattern == 5)
		sa(stack_a);
	else
		return ;
}

static void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	median;

	median = get_median(stack_a);
	if (stack_size(stack_a) > 6)
		return ;
	while (stack_size(stack_a) > 3)
	{
		if (stack_size(stack_a) % 2 == 0 && stack_a->top->data <= median)
			pb(stack_a, stack_b);
		else if (stack_size(stack_a) % 2 != 0 && stack_a->top->data < median)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_one_two_three(stack_a);
	sort_b(stack_b);
	while (is_stack_empty(stack_b) == FALSE)
	{
		while (stack_top(stack_a) < stack_top(stack_b))
			ra(stack_a);
		pa(stack_a, stack_b);
		while (stack_a->head->data < stack_top(stack_a))
			rra(stack_a);
	}
}

int	sort_one_two_three(t_stack *stack_a)
{
	size_t	size;

	size = stack_size(stack_a);
	if (size <= 1 || is_stack_sorted_a(stack_a))
		return (COMPLETE);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three_numbers(stack_a);
	else
		return (CONTINUE);
	return (COMPLETE);
}

int	sort_a(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size;

	size = stack_size(stack_a);
	if (sort_one_two_three(stack_a) == COMPLETE)
		return (COMPLETE);
	else if (size <= 6 && is_stack_empty(stack_b) == TRUE)
		sort_small(stack_a, stack_b);
	else
		return (CONTINUE);
	return (COMPLETE);
}
