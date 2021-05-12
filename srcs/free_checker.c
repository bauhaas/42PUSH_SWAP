/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 02:50:28 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/12 16:26:23 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void			free_cmd(t_list *cmd)
{
	t_list		*ptr_list;
	t_list		*ptr_next;

	ptr_list = cmd;
	while (ptr_list)
	{
		ptr_next = ptr_list->next;
		if (ptr_list->content)
			ft_strdel(ptr_list->content);
		free(ptr_list->content);
		free(ptr_list);
		ptr_list = ptr_next;
	}
	cmd = NULL;
}

void			free_list(void *content)
{
	char	*e;

	e = (char *)content;
	ft_strdel(&e);
}

void			free_stack(t_stack *stack)
{
	t_stack		*ptr_list;
	t_stack		*ptr_next;

	ptr_list = stack;
	while (ptr_list)
	{
		ptr_next = ptr_list->next;
		free(ptr_list);
		ptr_list = ptr_next;
	}
	stack = NULL;
}

void			free_checker(t_checker *checker)
{
	ft_free_strs(&checker->expanded_params);
	ft_lstclear(&checker->head_cmd, &free_list);
	free(checker->arr);
	free_stack(checker->stacks->a);
	free_stack(checker->stacks->b);
	free(checker->stacks);
	checker->stacks = NULL;
}
