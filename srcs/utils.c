/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:58:33 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/12 18:02:49 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int			is_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int			is_empty(t_stack *stack)
{
	if (!stack)
	{
		printf("B is empty :)\n");
		return (1);
	}
	printf("B isn't empty :(\n");
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
		{
			printf("A isn't sorted :(\n");
			return (0);
		}
		tmp = tmp->next;
	}
	printf("A is sorted :)\n");
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
