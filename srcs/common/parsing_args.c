/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:15:43 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 16:39:59 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		*free_and_ret(int **arr)
{
	free(*arr);
	*arr = NULL;
	return (*arr);
}

int				ft_strarr_len(char **arr)
{
	int i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}

int				*str_array_to_int_array(char **src, int size)
{
	long long	new_element;
	int			*arr;
	int			i;

	arr = malloc(sizeof(int) * (size));
	i = -1;
	while (++i < size)
	{
		if (ft_isnumb(src[i]))
		{
			new_element = ft_atoll(src[i]);
			if (new_element >= INT_MIN && new_element <= INT_MAX)
				arr[i] = new_element;
			else
				return (free_and_ret(&arr));
		}
		else
			return (free_and_ret(&arr));
	}
	return (arr);
}
