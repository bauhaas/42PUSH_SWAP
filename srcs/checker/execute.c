/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 03:02:14 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:41:45 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void		select_swap(t_checker *checker, t_stacks *stacks, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		swap_stack(checker, &stacks->a->i, &stacks->a->next->i, 0);
	else if (!ft_strcmp(cmd, "sb"))
		swap_stack(checker, &stacks->b->i, &stacks->b->next->i, 0);
	else if (!ft_strcmp(cmd, "ss"))
	{
		swap_stack(checker, &stacks->a->i, &stacks->a->next->i, 0);
		swap_stack(checker, &stacks->b->i, &stacks->b->next->i, 0);
	}
}

void		select_push(t_checker *checker, char *cmd)
{
	if (!ft_strcmp(cmd, "pa"))
		push_stack(checker, &checker->stacks->b, &checker->stacks->a, 0);
	else if (!ft_strcmp(cmd, "pb"))
		push_stack(checker, &checker->stacks->a, &checker->stacks->b, 0);
}

void		select_rotate(t_checker *checker, char *cmd)
{
	if (!ft_strcmp(cmd, "ra"))
		rotate_stack(checker, &checker->stacks->a, 0);
	else if (!ft_strcmp(cmd, "rb"))
		rotate_stack(checker, &checker->stacks->b, 0);
	else if (!ft_strcmp(cmd, "rr"))
	{
		rotate_stack(checker, &checker->stacks->a, 0);
		rotate_stack(checker, &checker->stacks->b, 0);
	}
}

void		select_rev_rotate(t_checker *checker, char *cmd)
{
	if (!ft_strcmp(cmd, "rra"))
		reverse_rotate_stack(checker, &checker->stacks->a, 0);
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate_stack(checker, &checker->stacks->b, 0);
	else if (!ft_strcmp(cmd, "rrr"))
	{
		reverse_rotate_stack(checker, &checker->stacks->a, 0);
		reverse_rotate_stack(checker, &checker->stacks->b, 0);
	}
}

void		execute(t_checker *checker)
{
	char *cmd;

	if (checker->cmd)
	{
		while (checker->cmd)
		{
			cmd = (char *)checker->cmd->content;
			if (cmd[0] == 's')
				select_swap(checker, checker->stacks, cmd);
			else if (cmd[0] == 'p')
				select_push(checker, cmd);
			else if (cmd[0] == 'r' && ft_strlen(cmd) == 2)
				select_rotate(checker, cmd);
			else if (cmd[0] == 'r' && ft_strlen(cmd) == 3)
				select_rev_rotate(checker, cmd);
			checker->cmd = checker->cmd->next;
		}
	}
}
