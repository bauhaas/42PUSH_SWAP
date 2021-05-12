/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 02:31:39 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/12 18:37:49 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

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

void	create_cmd(t_checker *checker, char *line)
{
	t_list *new;
	t_list *tmp;

	tmp = checker->cmd;
	new = ft_memalloc(sizeof(t_list));
	new->content = ft_strdup(line);
	if (checker->cmd == NULL)
		checker->cmd = new;
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
			create_cmd(checker, line);
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
