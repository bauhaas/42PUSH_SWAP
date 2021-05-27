/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 02:50:28 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 16:36:55 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void			free_list(void *content)
{
	char	*e;

	e = (char *)content;
	ft_strdel(&e);
}

static void			free_stack(t_stack *stack)
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

void				free_ps(t_ps *ps)
{
	ft_free_strs(&ps->expanded_params);
	ft_lstclear(&ps->head_cmd, &free_list);
	ft_lstclear(&ps->cmd, &free_list);
	free(ps->arr);
	free_stack(ps->stacks->a);
	free_stack(ps->stacks->b);
	free(ps->stacks);
	ps->stacks = NULL;
}
