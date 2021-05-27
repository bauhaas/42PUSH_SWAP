/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:20:19 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 18:21:02 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int			main(int ac, char **av)
{
	t_ps	ps;

	if (ac <= 1)
		return (0);
	init_ps(&ps, av);
	if (has_duplicates(ps.arr, ps.tot_params) || ps.arr == NULL)
	{
		free_ps(&ps);
		return (is_error());
	}
	if (!save_user_cmd(&ps))
	{
		free_ps(&ps);
		return (is_error());
	}
	set_stack_a(&ps, ps.arr, ps.tot_params);
	execute(&ps);
	if (is_empty(ps.stacks->b) && is_sort(ps.stacks->a))
		printf("OK\n");
	else
		printf("KO\n");
	free_ps(&ps);
	return (0);
}
