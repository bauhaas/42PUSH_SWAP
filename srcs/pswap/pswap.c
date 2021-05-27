/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:15:04 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 18:49:36 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Select the most efficient algorithm based on the initial size of stack A.
*/

static void		select_algo(t_ps *ps)
{
	int size;

	size = stack_size(ps->stacks->a);
	if (size == 1)
		return ;
	else if (size == 2)
		two_elements(ps);
	else if (size <= 3)
		three_elements(ps);
	else if (size <= 5)
		five_elements(ps);
	else if (size <= 100)
		sort(ps, ps->stacks, 30);
	else if (size <= 500)
		sort(ps, ps->stacks, 70);
	else
		return ;
}

int				main(int ac, char **av)
{
	t_ps ps;

	ps.cmd = NULL;
	if (ac == 1)
		return (0);
	init_ps(&ps, av);
	if (has_duplicates(ps.arr, ps.tot_params) || ps.arr == NULL)
	{
		free_ps(&ps);
		return (is_error());
	}
	set_stack_a(&ps, ps.arr, ps.tot_params);
	if (is_sort(ps.stacks->a))
	{
		free_ps(&ps);
		return (0);
	}
	select_algo(&ps);
	optimize_cmd_lst(&ps);
	print_cmd_lst(ps.head_cmd);
	free_ps(&ps);
	return (0);
}
