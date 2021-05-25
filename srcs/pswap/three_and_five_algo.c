/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_and_five_algo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:09:07 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:13:58 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void		two_elements(t_checker *checker)
{
	if (checker->stacks->a->i > checker->stacks->a->next->i)
		swap_stack(checker, &checker->stacks->a->i,
				&checker->stacks->a->next->i, "sa");
}

void		three_elements(t_checker *checker)
{
	t_stack *first;
	t_stack *secnd;
	t_stack *third;

	first = checker->stacks->a;
	secnd = checker->stacks->a->next;
	third = checker->stacks->a->next->next;
	if (first->i > secnd->i && first->i < third->i && secnd->i < third->i)
		swap_stack(checker, &first->i, &secnd->i, "sa");
	else if (first->i > secnd->i && first->i > third->i && secnd->i > third->i)
	{
		swap_stack(checker, &first->i, &secnd->i, "sa");
		reverse_rotate_stack(checker, &checker->stacks->a, "rra");
	}
	else if (first->i > secnd->i && first->i > third->i && secnd->i < third->i)
		rotate_stack(checker, &checker->stacks->a, "ra");
	else if (first->i < secnd->i && first->i < third->i && secnd->i > third->i)
	{
		swap_stack(checker, &first->i, &secnd->i, "sa");
		rotate_stack(checker, &checker->stacks->a, "ra");
	}
	else if (first->i < secnd->i && first->i > third->i && secnd->i > third->i)
		reverse_rotate_stack(checker, &checker->stacks->a, "rra");
}

/*
** Return the index of the smallest element
*/

static int	smallest_value_position(t_stack *stack, int smallest)
{
	t_stack	*tmp;
	int		pos;
	int		i;

	tmp = stack;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->i == smallest)
		{
			pos = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

/*
** Depending on the position of the element we are looking for, we will rra or
** ra if the element is closer to the head or the end of our list. Allow us
** to minimize commands to make.
*/

static void	put_smallest_on_top(t_checker *checker, t_stack **head, int pos)
{
	int		size;
	t_stack *tmp;

	tmp = *head;
	size = stack_size(tmp);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos-- > 0)
			reverse_rotate_stack(checker, head, "rra");
	}
	else if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate_stack(checker, head, "ra");
	}
}

/*
** We look for the smallest value and put it at the top of the A stack, and we
** are doing it a 2nd time to have only 3 elements in A
** Then we sort the 3 left numbers in A and push back the 2 numbers that were
** on B stack.
*/

void		five_elements(t_checker *checker)
{
	int	size;
	int	pos;
	int	i;

	size = stack_size(checker->stacks->a);
	i = 0;
	while (i < (size - 3))
	{
		pos = smallest_value_position(checker->stacks->a, (i + 1));
		put_smallest_on_top(checker, &checker->stacks->a, pos);
		push_stack(checker, &checker->stacks->a, &checker->stacks->b, "pb");
		i++;
	}
	three_elements(checker);
	while (i-- > 0)
		push_stack(checker, &checker->stacks->b, &checker->stacks->a, "pa");
}
