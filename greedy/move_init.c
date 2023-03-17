/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:38 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/15 16:17:59 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_small_and_middle_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*dummy;
	size_t			size;

	dummy = stack_a->top;
	size = stack_a->size;
	while (dummy != NULL && size)
	{
		if (stack_a->big_pivot >= dummy->data)
		{
			dummy = dummy->prev;
			pb(stack_a, stack_b);
			if (stack_b->top->data <= stack_a->small_pivot)
				rb(stack_b);
		}
		else
		{
			dummy = dummy->prev;
			ra(stack_a);
		}
		size--;
	}
}

static void	move_big_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*dummy;

	dummy = stack_a->top;
	while (dummy != NULL && sort_a(stack_a, stack_b) == CONTINUE)
	{
		dummy = dummy->prev;
		pb(stack_a, stack_b);
	}
}

void	move_init(t_stack *stack_a, t_stack *stack_b)
{
	get_pivot(stack_a);
	move_small_and_middle_to_b(stack_a, stack_b);
	move_big_to_b(stack_a, stack_b);
}
