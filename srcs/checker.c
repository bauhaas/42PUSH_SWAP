/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:20:19 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/12 19:01:44 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../libft/libft.h"

t_stack		*new_stack(int value)
{
	t_stack *new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	if (new_stack)
	{
		new_stack->i = value;
		new_stack->next = NULL;
	}
	return (new_stack);
}

void		fill_stack_a(t_stack **stack, int value)
{
	t_stack *new;
	t_stack *tmp;

	tmp = *stack;
	new = NULL;
	new = malloc(sizeof(t_stack) * 1);
	new->i = value;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		if (tmp)
		{
			while (tmp != NULL && tmp->next != NULL)
				tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void		set_stack_a(t_checker *checker, int *arr, int size)
{
	t_stack	*new;
	int		i;

	i = 0;
	new = NULL;
	if (arr)
	{
		while (arr && i < size)
		{
			fill_stack_a(&checker->stacks->a, arr[i]);
			i++;
		}
	}
}

int			main(int ac, char **av)
{
	t_checker	checker;

	if (ac <= 1)
		return (0);
	init_checker(&checker, av);
	//print_valid_char_arr_format(expanded_params);
	if (has_duplicates(checker.arr, checker.tot_params) || checker.arr == NULL)
	{
		free_checker(&checker);
		return (is_error());
	}
	if (!save_user_cmd(&checker))
	{
		free_checker(&checker);
		return (is_error());
	}
	set_stack_a(&checker, checker.arr, checker.tot_params);
	//print_stack(checker.stacks->a);
	//print_cmd_lst(&checker);
	execute(&checker);
	//print_after_exec(&checker);
	if (is_empty(checker.stacks->b) && is_sort(checker.stacks->a))
		printf("OK\n");
	else
		printf("KO\n");
	free_checker(&checker);
	return (0);
}
