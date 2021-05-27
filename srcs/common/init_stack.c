/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:36:11 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:09:23 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack		*new_stack(int value)
{
	t_stack *new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	if (new_stack)
	{
		new_stack->i = value;
		new_stack->next = NULL;
	}
	return (new_stack);
}

void		fill_stack_a(t_stack **stack, int value)
{
	t_stack *new;
	t_stack *tmp;

	tmp = *stack;
	new = NULL;
	new = malloc(sizeof(t_stack) * 1);
	new->i = value;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		if (tmp)
		{
			while (tmp != NULL && tmp->next != NULL)
				tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void		set_stack_a(t_ps *ps, int *arr, int size)
{
	t_stack	*new;
	int		i;

	i = 0;
	new = NULL;
	if (arr)
	{
		while (arr && i < size)
		{
			fill_stack_a(&ps->stacks->a, arr[i]);
			i++;
		}
	}
}
