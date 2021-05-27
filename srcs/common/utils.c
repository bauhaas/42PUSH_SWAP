/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:58:33 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 16:04:57 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			stack_size(t_stack *head)
{
	int		i;
	t_stack	*list;

	if (!head)
		return (0);
	list = head;
	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int			is_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int			is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (0);
}

int			is_sort(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->next && (tmp->i > tmp->next->i))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			has_duplicates(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr && arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
