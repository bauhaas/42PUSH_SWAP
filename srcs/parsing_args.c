/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:15:43 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/12 03:17:31 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int		ft_strarr_len(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		*str_array_to_int_array(char **src, int size)
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
				break ;
		}
		else
			break ;
	}
	return (arr);
}

int		has_duplicates(int *arr, int size)
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
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
