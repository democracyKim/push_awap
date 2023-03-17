/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:58:11 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/14 18:56:09 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*list;

	list = calloc(1, sizeof(t_stack));
	if (!list)
		return (NULL);
	list->size = 0;
	return (list);
}

t_stack_node	*create_new_node(int data)
{
	t_stack_node	*new_node;

	new_node = calloc(1, sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	return (new_node);
}

int	push(t_stack *stack, int data)
{
	t_stack_node	*new_node;

	if (stack == NULL)
		return (-1);
	new_node = create_new_node(data);
	if (stack->head == NULL)
		stack->head = new_node;
	else
	{
		stack->top->next = new_node;
		new_node->prev = stack->top;
	}
	stack->top = new_node;
	stack->size++;
	return (0);
}

int	put_stack(t_stack *stack, int data)
{
	t_stack_node	*new_node;

	if (stack == NULL)
		return (-1);
	new_node = create_new_node(data);
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->top = new_node;
	}
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
	return (0);
}

int	pop(t_stack *stack)
{
	int				data;
	t_stack_node	*del_node;

	if (!stack || !stack->top)
		return (-1);
	data = stack->top->data;
	del_node = stack->top;
	stack->top = stack->top->prev;
	if (stack->top)
		stack->top->next = NULL;
	else
		stack->head = NULL;
	free(del_node);
	stack->size--;
	return (data);
}
