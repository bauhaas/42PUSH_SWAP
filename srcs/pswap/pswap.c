/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:15:04 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:25:08 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

/*
** Select the most efficient algorithm based on the initial size of stack A.
*/

void		select_algo(t_checker *checker)
{
	int size;

	size = stack_size(checker->stacks->a);
	checker->cmd_nb = 0;
	if (size == 1)
		return ;
	else if (size == 3)
		two_elements(checker);
	else if (size <= 3 + 1)
		three_elements(checker);
	else if (size <= 5 + 1)
		five_elements(checker);
	else if (size <= 100 + 1)
		sort(checker, checker->stacks, 30);
	else if (size <= 500 + 1)
		sort(checker, checker->stacks, 70);
	else
		return ;
}

int			main(int ac, char **av)
{
	t_checker ps;

	ps.cmd = NULL;
	if (ac == 1)
		return (0);
	init_checker(&ps, av);
	if (has_duplicates(ps.arr, ps.tot_params) || ps.arr == NULL)
	{
		free_checker(&ps);
		return (is_error());
	}
	set_stack_a(&ps, ps.arr, ps.tot_params);
	select_algo(&ps);
	//printf("End stack A\n");
	//print_stack(ps.stacks->a);
	//printf("End stack B\n");
	//print_stack(ps.stacks->b);
//	printf("TOTAL CMD NB : %d\n", ps.cmd_nb);
//	printf("LIST OF CMD\n");
//	print_cmd_lst(ps.cmd);
	optimize_cmd_lst(&ps);
	print_cmd_lst(ps.head_cmd);
	free_checker(&ps);
	return (0);
}
