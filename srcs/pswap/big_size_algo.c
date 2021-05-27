/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:58:15 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 17:37:20 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Based on the index of the value we decided to push back to B
** we determine if it's placed closer to the head or the
** end of our B stack and then put it to head and push it back to A.
*/

static void		put_select_id_on_top_and_push(t_ps *ps, int id, int size)
{
	if (id < size / 2)
		while (id--)
			rotate_stack(ps, &ps->stacks->b, "rb");
	else
		while (id++ < size)
			reverse_rotate_stack(ps, &ps->stacks->b, "rrb");
	push_stack(ps, &ps->stacks->b, &ps->stacks->a, "pa");
}

/*
** Determine the index of the smallest and biggest value in B, and based on the
** position, we push it back to A. If it's the smallest we put it at the end of
** A, otherwise, we store it at the top of A and will rotate A when we'll have
** fully cleared B.
*/

static void		selection_sort_remix(t_ps *ps, t_stacks *stacks)
{
	int	size;
	int	id_to_push;
	int	id_of_smallest;
	int	id_of_biggest;
	int	i;

	size = stack_size(stacks->b);
	i = 0;
	while (stacks->b)
	{
		id_of_smallest = select_id(stacks->b, select_min(stacks->b));
		id_of_biggest = select_id(stacks->b, select_max(stacks->b));
		id_to_push = select_id_to_push(id_of_smallest, id_of_biggest, size);
		put_select_id_on_top_and_push(ps, id_to_push, size);
		if (id_to_push == id_of_smallest)
			rotate_stack(ps, &stacks->a, "ra");
		else
			i++;
		size--;
	}
	while (i--)
		rotate_stack(ps, &stacks->a, "ra");
}

/*
** Return true of false if there is a value under the pivot in the stacked
** sent as parameter.
*/

static int		has_value_under_pivot_value(t_stack *stack, int pivot)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->i <= pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
** 1. We push elements to B if it's less than pivot until we reached id_limit
** or there is no more value under pivot value
** 2. Put to the end of A stack the sorted value (doesn't have to on 1st and
** last call of the function)
** 3. sort value pushed on B.
** It returns the amount of elements that has been sorted on B to reduce the
** id_limit on the next block.
*/

static int		partition(t_ps *ps, int id_limit, int pivot, int size)
{
	int	size_max;

	size = stack_size(ps->stacks->a) - id_limit;
	while (ps->stacks->a && id_limit--)
		if (ps->stacks->a->i <= pivot)
			push_stack(ps, &ps->stacks->a, &ps->stacks->b, "pb");
		else
		{
			if (!has_value_under_pivot_value(ps->stacks->a, pivot))
				break ;
			rotate_stack(ps, &ps->stacks->a, "ra");
		}
	size_max = stack_size(ps->stacks->a);
	if (size < size_max)
	{
		if (size < size_max / 2)
			while (size--)
				rotate_stack(ps, &ps->stacks->a, "ra");
		else
			while (size++ < size_max)
				reverse_rotate_stack(ps, &ps->stacks->a, "rra");
	}
	size = stack_size(ps->stacks->b);
	selection_sort_remix(ps, ps->stacks);
	return (size);
}

/*
** sort the element by blocks (block number based on divide size)
** size = number of elements in A
** total_block = number of blocks we will make and sort
** curr_block = actual block we are working on
** index_limit = the highest index we will go to make modification
** pivot = value to start sorting
** partition return the number of elements that have been sorted and ajust
** the new index_limit
*/

void			sort(t_ps *ps, t_stacks *stacks, int divide_block_size)
{
	int	size;
	int	total_block;
	int	curr_block;
	int pivot;
	int	id_limit;

	size = stack_size(stacks->a);
	id_limit = size;
	curr_block = 0;
	total_block = size / divide_block_size;
	if (size > size / divide_block_size * divide_block_size)
		total_block++;
	while (curr_block++ < total_block)
	{
		pivot = select_pivot(*stacks, curr_block, total_block);
		id_limit -= partition(ps, id_limit, pivot, size);
	}
}
