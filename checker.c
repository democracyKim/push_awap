/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:53:31 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/15 16:05:14 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(operation, "sa\n") == EQUAL)
		sa(stack_a);
	else if (ft_strcmp(operation, "sb\n") == EQUAL)
		sb(stack_b);
	else if (ft_strcmp(operation, "ss\n") == EQUAL)
		ss(stack_a, stack_b);
	else if (ft_strcmp(operation, "pa\n") == EQUAL)
		pa(stack_a, stack_b);
	else if (ft_strcmp(operation, "pb\n") == EQUAL)
		pb(stack_a, stack_b);
	else if (ft_strcmp(operation, "ra\n") == EQUAL)
		ra(stack_a);
	else if (ft_strcmp(operation, "rb\n") == EQUAL)
		rb(stack_b);
	else if (ft_strcmp(operation, "rr\n") == EQUAL)
		rr(stack_a, stack_b);
	else if (ft_strcmp(operation, "rra\n") == EQUAL)
		rra(stack_a);
	else if (ft_strcmp(operation, "rrb\n") == EQUAL)
		rrb(stack_b);
	else if (ft_strcmp(operation, "rrr\n") == EQUAL)
		rrr(stack_a, stack_b);
	else
		return (FALSE);
	return (TRUE);
}

static void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*operation;

	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL)
			break ;
		if (is_operation(operation, stack_a, stack_b) == FALSE)
		{
			ft_printf("Error\n");
			destroy_stacks_and_exit(stack_a, stack_b, ERROR);
		}
		free(operation);
	}
}

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
	checker(stack_a, stack_b);
	if (is_stack_sorted_a(stack_a) && is_stack_empty(stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	destroy_stacks_and_exit(stack_a, stack_b, COMPLETE);
	return (0);
}
