/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:25:41 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/16 17:36:00 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	get_max_index(t_stack *stack)
{
	t_stack_node	*dummy;
	size_t			index;
	int				max;
	size_t			max_index;

	if (stack == NULL || stack->top == NULL)
		return (0);
	dummy = stack->top;
	max = 0;
	index = 0;
	max_index = 0;
	while (dummy)
	{
		if (dummy->data > max)
		{
			max = dummy->data;
			max_index = index;
		}
		dummy = dummy->prev;
		index++;
	}
	return (max_index);
}

void	min_to_top(t_stack *stack_a)
{
	size_t	max_index;
	size_t	size;

	max_index = get_max_index(stack_a);
	size = stack_size(stack_a);
	if (stack_a == NULL || stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	while (is_biggest_num(stack_a, stack_a->head->data) == FALSE)
	{
		if (max_index > size / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

int	is_biggest_num(t_stack *stack_a, int number)
{
	t_stack_node	*dummy;

	if (stack_a == NULL || stack_a->top == NULL)
		return (TRUE);
	dummy = stack_a->top;
	while (dummy)
	{
		if (dummy->data > number)
			return (FALSE);
		dummy = dummy->prev;
	}
	return (TRUE);
}
