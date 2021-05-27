/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:23:38 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 18:17:17 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Find the pivot, based on max and min value.
** If we are on the last block to sort, then we return max value.
*/

int		select_pivot(t_stacks stacks, int index, int division)
{
	int	max;
	int	min;

	max = select_max(stacks.a);
	min = select_min(stacks.a);
	if (index < division)
		return ((max - min) * index / division + min + 10);
	return (max);
}

/*
** Return the index of the valued we picked to be sent back to A.
*/

int		select_id_to_push(int id_of_smallest, int id_of_biggest, int size)
{
	int	total_cmd_to_push_small;
	int	total_cmd_to_push_big;

	if (id_of_smallest < size / 2)
		total_cmd_to_push_small = id_of_smallest;
	else
		total_cmd_to_push_small = size - id_of_smallest;
	if (id_of_biggest < size / 2)
		total_cmd_to_push_big = id_of_biggest;
	else
		total_cmd_to_push_big = size - id_of_biggest;
	if (total_cmd_to_push_small > total_cmd_to_push_big)
		return (id_of_biggest);
	return (id_of_smallest);
}

/*
** Return smallest value in stack.
*/

int		select_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->i;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->i < min)
			min = stack->i;
	}
	return (min);
}

/*
** Return biggest value in stack.
*/

int		select_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->i;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->i > max)
			max = stack->i;
	}
	return (max);
}

/*
** Return index of the picked value in stack.
*/

int		select_id(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->i == value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}
