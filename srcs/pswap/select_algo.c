/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:58:15 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:33:19 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	bestindex(int index1, int index2, int len)
{
	int	index1_mov;
	int	index2_mov;

	if (index1 < len / 2)
		index1_mov = index1;
	else
		index1_mov = len - index1;
	if (index2 < len / 2)
		index2_mov = index2;
	else
		index2_mov = len - index2;
	if (index1_mov > index2_mov)
		return (index2);
	return (index1);
}

/*
 ** We are using the same logic as the 5 elements sort. Based on the index of 
 ** the smallest value, we determine if it's placed closer to the head or the
 ** end of our B stack and then put it to the head to push it back to A.
 */

void	put_smallest_on_top_and_push(t_checker *checker, t_stacks *stacks, int index, int len)
{
	if (index < len / 2)
		while (index--)
		{
			checker->cmd_nb++;
			rotate_stack(checker, &stacks->b, "rb");
		}
	else
		while (index++ < len)
		{
			checker->cmd_nb++;
			reverse_rotate_stack(checker, &stacks->b, "rrb");
		}
	checker->cmd_nb++;
	push_stack(checker, &stacks->b, &stacks->a, "pa");
}

/*
** Now, we'll sort the block placed on B and push it back to A
*/

void	sort_b(t_checker *checker, t_stacks *stacks)
{
	int	len;
	int	index;
	int	min;
	int	top;

	len = getlen(stacks->b);
	top = 0;
//	printf("STACK B IN SORT\n");
//	print_stack(stacks->b);
	while (stacks->b)
	{
		min = getindex(stacks->b, getmin(stacks->b));
		index = bestindex(min, getindex(stacks->b, getmax(stacks->b)), len);
		put_smallest_on_top_and_push(checker, stacks, index, len);
	//	print_stack(stacks->b);
		if (index == min)
		{
			checker->cmd_nb++;
			rotate_stack(checker, &stacks->a, "ra");
		}
		else
			top++;
		len--;
	}
	while (top--)
	{
		checker->cmd_nb++;
		rotate_stack(checker, &stacks->a, "ra");
	}
}

int	sort_partition(t_checker *checker, t_stacks *stacks, int i_max, int pivot)
{
	int	len_total;
	int	len;

	//printf("PIVOT = %d\n", pivot);
	//printf("I_max = %d\n", pivot);
	len = getlen(stacks->a) - i_max;
	while (stacks->a && i_max--)
		if (stacks->a->i <= pivot)
		{
			checker->cmd_nb++;
			push_stack(checker, &stacks->a, &stacks->b, "pb");
		}
		else
		{
			checker->cmd_nb++;
			rotate_stack(checker, &stacks->a, "ra");
		}
	len_total = getlen(stacks->a);
	if (len < len_total)
	{
		if (len < len_total / 2)
			while (len--)
			{
				checker->cmd_nb++;
				rotate_stack(checker, &stacks->a, "ra");
			}
		else
			while (len++ < len_total)
			{
				checker->cmd_nb++;
				reverse_rotate_stack(checker, &stacks->a, "rra");
			}
	}
	len = getlen(stacks->b);
	//printf("len of B stack before sorting it : %d\n", len);
//	printf("befor sort stack B\n");
//	print_stack(checker->stacks->b);
	sort_b(checker, stacks);
//	printf("endpartition stack A\n");
//	print_stack(checker->stacks->a);
	return (len);
}

/*
 ** sort the element by blocks (block number based on divide size)
 ** size = number of elements in A
 ** division = number of blocks we will make and sort
 ** index = actual block id
 ** indexmax = the highest index we will go to make modification 
 ** 
 ** sort_partition return the number of elements that have been sorted and ajust
 ** the new max index
 ** 
 */

void	sort(t_checker *checker, t_stacks *stacks, int divide_size)
{
	int	size;
	int	division;
	int	index;
	int	indexmax;

	size = stack_size(stacks->a);
	division = size / divide_size;
	if (size > size / divide_size * divide_size)
		division++;
	indexmax = size;
	index = 0;

	/*
	printf("INIT INDEXMAX : %d\n", indexmax);
	printf("INIT DIVISION : %d\n", division);
	printf("INIT INDEX : %d\n", index);
	printf("INIT SIZE : %d\n", size);
	*/

	while (index++ < division)
	{
		//pivot is always last elem of my divided block

		//printf("index max in loop : %d\n", indexmax);
		//printf("division in loop : %d\n", division);
		int pivot = getpivot(*stacks, index, division, divide_size);	
		//printf("index max in loop 2: %d\n", indexmax);
		int lol = sort_partition(checker, stacks, indexmax, pivot);
		indexmax = indexmax - lol;
		//printf("A LIST\n");
		//print_stack(checker->stacks->a);
	}
}
