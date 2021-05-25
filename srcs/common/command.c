/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 02:31:39 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:09:07 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int		is_valid_cmd(char *line)
{
	if (!ft_strcmp(line, "sa") ||
			!ft_strcmp(line, "sb") ||
			!ft_strcmp(line, "ss") ||
			!ft_strcmp(line, "pa") ||
			!ft_strcmp(line, "pb") ||
			!ft_strcmp(line, "ra") ||
			!ft_strcmp(line, "rb") ||
			!ft_strcmp(line, "rr") ||
			!ft_strcmp(line, "rra") ||
			!ft_strcmp(line, "rrb") ||
			!ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}

void	create_cmd(t_list **lst, char *line)
{
	t_list *new;
	t_list *tmp;

	tmp = *lst;
	new = ft_memalloc(sizeof(t_list));
	new->content = ft_strdup(line);
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp != NULL && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		save_user_cmd(t_checker *checker)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (is_valid_cmd(line))
			create_cmd(&checker->cmd, line);
		else
		{
			free(line);
			checker->head_cmd = checker->cmd;
			return (0);
		}
		free(line);
		line = NULL;
	}
	free(line);
	checker->head_cmd = checker->cmd;
	return (1);
}

int		is_cmd_linked(char *cmd, t_list *next, char *b, char *a)
{
	if ((!ft_strcmp(cmd, a) && (next && !ft_strcmp(next->content, b))) ||
	((!ft_strcmp(cmd, b) && (next && !ft_strcmp(next->content, a)))))
		return (1);
	return (0);
}

void	optimize_cmd_lst(t_checker *checker)
{
	t_list *old;

	old = checker->cmd;
	while (old)
	{
		if (is_cmd_linked(old->content, old->next, "sa", "sb"))
		{
			create_cmd(&checker->head_cmd, "ss");
			old = old->next;
		}
		else if (is_cmd_linked(old->content, old->next, "ra", "rb"))
		{
			create_cmd(&checker->head_cmd, "rr");
			old = old->next;
		}
		else if (is_cmd_linked(old->content, old->next, "rra", "rrb"))
		{
			create_cmd(&checker->head_cmd, "rrr");
			old = old->next;
		}
		else
			create_cmd(&checker->head_cmd, (char *)old->content);
		old = old->next;
	}
}
