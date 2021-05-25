/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:23:38 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:41:58 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

/*
** Find the pivot, based on max and min value.
** If we are on the last block to sort, then we return max value.
*/

int	getpivot(t_stacks stacks, int index, int division, int divide_size)
{
	int	max;
	int	min;

	max = getmax(stacks.a);
	min = getmin(stacks.a);

	/*
	printf("\nPIVOT SELECTION\n");
	printf("max : %d\n", max);
	printf("min : %d\n", min);
	printf("index : %d\n", index);
	printf("division : %d\n", division);
	*/

	if (index < division)
	{
	//	printf("pivot selected : %d\n\n", ((max - min) * index / division + min));
		return ((max - min) * index / division + min + 10); //+10 a bit better
	}
	//printf("pivot selected : %d\n\n", max);
	return (max);
}

int		getlen(t_stack *item)
{
	int	len;

	len = 0;
	while (item)
	{
		len++;
		item = item->next;
	}
	return (len);
}

int		getmin(t_stack *item)
{
	int	min;

	if (!item)
		return (0);
	min = item->i;
	while (item->next)
	{
		item = item->next;
		if (item->i < min)
			min = item->i;
	}
	return (min);
}

int		getmax(t_stack *item)
{
	int	max;

	if (!item)
		return (0);
	max = item->i;
	while (item->next)
	{
		item = item->next;
		if (item->i > max)
			max = item->i;
	}
	return (max);
}

int		getindex(t_stack *item, int nbr)
{
	int	index;

	index = 0;
	while (item)
	{
		if (item->i == nbr)
			return (index);
		index++;
		item = item->next;
	}
	return (0);
}
