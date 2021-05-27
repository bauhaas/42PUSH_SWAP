/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:28:36 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 18:35:45 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_valid_char_arr_format(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		printf("char array final format[%d] : %s \n", i, arr[i]);
		i++;
	}
}

void	print_av(int ac, char **av)
{
	int i;

	i = 0;
	printf("total ac : %d\n", ac);
	while (av[i])
	{
		if (av[i][0])
			printf("av[%d]: %s\n", i, av[i]);
		i++;
	}
	printf("\n");
}

void	print_cmd_lst(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	if (tmp)
	{
		while (tmp)
		{
			printf("stack[%d] : %d", i, tmp->i);
			if (tmp->next)
				printf("    stack[%d]->next : %d\n", i, tmp->next->i);
			else
				printf("\n");
			tmp = tmp->next;
			i++;
		}
	}
}

void	print_after_exec(t_ps *ps)
{
	printf("\nA STCK AFTER EXEC\n");
	print_stack(ps->stacks->a);
	printf("\nB STCK AFTER EXEC\n\n");
	print_stack(ps->stacks->b);
}
