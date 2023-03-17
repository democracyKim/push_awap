/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:44:14 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/15 16:31:49 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = create_stack();
	if (!stack_a)
		return (ERROR);
	if (fill_stack(stack_a, argc, argv) == -1)
		return (ERROR);
	stack_b = create_stack();
	if (!stack_b)
		return (ERROR);
	if (is_stack_sorted_a(stack_a))
		destroy_stacks_and_exit(stack_a, stack_b, 0);
	if (sort_a(stack_a, stack_b) == COMPLETE)
	{
		destroy_stacks_and_exit(stack_a, stack_b, 0);
		return (0);
	}
	move_init(stack_a, stack_b);
	apply_greedy(stack_a, stack_b);
	destroy_stacks_and_exit(stack_a, stack_b, 0);
	return (0);
}
