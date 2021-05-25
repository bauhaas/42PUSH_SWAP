/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:20:19 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:43:03 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"
#include "../../libft/libft.h"

int			main(int ac, char **av)
{
	t_checker	checker;

	if (ac <= 1)
		return (0);
	init_checker(&checker, av);
	if (has_duplicates(checker.arr, checker.tot_params) || checker.arr == NULL)
	{
		printf("duplicate ou arr int empty\n");
		free_checker(&checker);
		return (is_error());
	}
	if (!save_user_cmd(&checker))
	{
		printf("save user cmd return false\n");
		free_checker(&checker);
		return (is_error());
	}
	set_stack_a(&checker, checker.arr, checker.tot_params);
	print_stack(checker.stacks->a);
	execute(&checker);
	if (is_empty(checker.stacks->b) && is_sort(checker.stacks->a))
		printf("OK\n");
	else
		printf("KO\n");
	print_stack(checker.stacks->a);
	free_checker(&checker);
	return (0);
}
