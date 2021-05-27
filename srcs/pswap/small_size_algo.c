/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:09:07 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 19:41:13 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	two_elements(t_ps *ps)
{
	if (ps->stacks->a->i > ps->stacks->a->next->i)
		swap_stack(ps, &ps->stacks->a->i,
			&ps->stacks->a->next->i, "sa");
}

void	three_elements(t_ps *ps)
{
	t_stack	*first;
	t_stack	*secnd;
	t_stack	*third;

	first = ps->stacks->a;
	secnd = ps->stacks->a->next;
	third = ps->stacks->a->next->next;
	if (first->i > secnd->i && first->i < third->i && secnd->i < third->i)
		swap_stack(ps, &first->i, &secnd->i, "sa");
	else if (first->i > secnd->i && first->i > third->i && secnd->i > third->i)
	{
		swap_stack(ps, &first->i, &secnd->i, "sa");
		reverse_rotate_stack(ps, &ps->stacks->a, "rra");
	}
	else if (first->i > secnd->i && first->i > third->i && secnd->i < third->i)
		rotate_stack(ps, &ps->stacks->a, "ra");
	else if (first->i < secnd->i && first->i < third->i && secnd->i > third->i)
	{
		swap_stack(ps, &first->i, &secnd->i, "sa");
		rotate_stack(ps, &ps->stacks->a, "ra");
	}
	else if (first->i < secnd->i && first->i > third->i && secnd->i > third->i)
		reverse_rotate_stack(ps, &ps->stacks->a, "rra");
}

/*
** Depending on the position of the element we are looking for, we will rra or
** ra if the element is closer to the head or the end of our list. Allow us
** to minimize commands to make.
*/

static void	put_smallest_on_top(t_ps *ps, t_stack **head, int pos)
{
	int		size;
	t_stack	*tmp;

	tmp = *head;
	size = stack_size(tmp);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos-- > 0)
			reverse_rotate_stack(ps, head, "rra");
	}
	else if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate_stack(ps, head, "ra");
	}
}

/*
** We look for the smallest value and put it at the top of the A stack, and we
** are doing it a 2nd time to have only 3 elements in A
** Then we sort the 3 left numbers in A and push back the 2 numbers that were
** on B stack.
*/

void	five_elements(t_ps *ps)
{
	int	size;
	int	pos;
	int	i;

	size = stack_size(ps->stacks->a);
	i = 0;
	while (i < (size - 3))
	{
		pos = select_id(ps->stacks->a, select_min(ps->stacks->a));
		put_smallest_on_top(ps, &ps->stacks->a, pos);
		push_stack(ps, &ps->stacks->a, &ps->stacks->b, "pb");
		i++;
	}
	three_elements(ps);
	while (i-- > 0)
		push_stack(ps, &ps->stacks->b, &ps->stacks->a, "pa");
}
