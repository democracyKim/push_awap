/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:12:10 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/16 10:25:49 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_stack_empty(t_stack *stack)
{
	return (stack == NULL || stack->top == NULL);
}

int	is_stack_sorted_a(t_stack *stack)
{
	t_stack_node	*below;
	int				data;

	if (stack == NULL || stack->head == NULL)
		return (TRUE);
	data = stack->top->data;
	below = stack->top->prev;
	while (below != NULL)
	{
		if (below->data < data)
			return (FALSE);
		data = below->data;
		below = below->prev;
	}
	return (TRUE);
}

int	is_stack_sorted_b(t_stack *stack)
{
	t_stack_node	*below;
	int				data;

	if (stack == NULL || stack->head == NULL)
		return (TRUE);
	data = stack->top->data;
	below = stack->top->prev;
	while (below != NULL)
	{
		if (below->data > data)
			return (FALSE);
		data = below->data;
		below = below->prev;
	}
	return (TRUE);
}

int	stack_min(t_stack *stack, int limit)
{
	t_stack_node	*curr;
	int				min;

	if (is_stack_empty(stack))
		return (INT_MIN);
	curr = stack->top;
	min = curr->data;
	while (curr && limit--)
	{
		if (curr->data < min)
			min = curr->data;
		curr = curr->next;
	}
	return (min);
}

int	stack_max(t_stack *stack, int range)
{
	t_stack_node	*node;
	int				max;

	node = stack->top;
	max = node->data;
	while (node && range--)
	{
		if (node->data > max)
			max = node->data;
		node = node->next;
	}
	return (max);
}
