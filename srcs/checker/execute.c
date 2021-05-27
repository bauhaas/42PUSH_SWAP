/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 03:02:14 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 19:48:41 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	select_swap(t_ps *ps, t_stacks *stacks, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		swap_stack(ps, &stacks->a->i, &stacks->a->next->i, 0);
	else if (!ft_strcmp(cmd, "sb"))
		swap_stack(ps, &stacks->b->i, &stacks->b->next->i, 0);
	else if (!ft_strcmp(cmd, "ss"))
	{
		swap_stack(ps, &stacks->a->i, &stacks->a->next->i, 0);
		swap_stack(ps, &stacks->b->i, &stacks->b->next->i, 0);
	}
}

static void	select_push(t_ps *ps, char *cmd)
{
	if (!ft_strcmp(cmd, "pa"))
		push_stack(ps, &ps->stacks->b, &ps->stacks->a, 0);
	else if (!ft_strcmp(cmd, "pb"))
		push_stack(ps, &ps->stacks->a, &ps->stacks->b, 0);
}

static void	select_rotate(t_ps *ps, char *cmd)
{
	if (!ft_strcmp(cmd, "ra"))
		rotate_stack(ps, &ps->stacks->a, 0);
	else if (!ft_strcmp(cmd, "rb"))
		rotate_stack(ps, &ps->stacks->b, 0);
	else if (!ft_strcmp(cmd, "rr"))
	{
		rotate_stack(ps, &ps->stacks->a, 0);
		rotate_stack(ps, &ps->stacks->b, 0);
	}
}

static void	select_rev_rotate(t_ps *ps, char *cmd)
{
	if (!ft_strcmp(cmd, "rra"))
		reverse_rotate_stack(ps, &ps->stacks->a, 0);
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate_stack(ps, &ps->stacks->b, 0);
	else if (!ft_strcmp(cmd, "rrr"))
	{
		reverse_rotate_stack(ps, &ps->stacks->a, 0);
		reverse_rotate_stack(ps, &ps->stacks->b, 0);
	}
}

void	execute(t_ps *ps)
{
	char	*cmd;

	if (ps->cmd)
	{
		while (ps->cmd)
		{
			cmd = (char *)ps->cmd->content;
			if (cmd[0] == 's')
				select_swap(ps, ps->stacks, cmd);
			else if (cmd[0] == 'p')
				select_push(ps, cmd);
			else if (cmd[0] == 'r' && ft_strlen(cmd) == 2)
				select_rotate(ps, cmd);
			else if (cmd[0] == 'r' && ft_strlen(cmd) == 3)
				select_rev_rotate(ps, cmd);
			ps->cmd = ps->cmd->next;
		}
	}
}
