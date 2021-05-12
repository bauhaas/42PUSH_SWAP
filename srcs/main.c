/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:20:19 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/12 03:16:26 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"
#include "../libft/libft.h"

int		is_error()
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

t_stack *new_stack(int value)
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

void create_stack(t_checker *checker, t_stack **stack, int value)
{
	t_stack *new;
	t_stack *tmp;

	tmp = *stack;
	new = malloc(sizeof(t_stack));
	new->i = value;
	if (*stack == NULL)
		*stack = new;
	else
	{
		while (tmp != NULL && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		set_stack_a(t_checker *checker, int *arr, int size)
{
	t_stack *new;
	int i;

	i = 0;
	new = NULL;
	if (arr)
	{
		while (arr && i < size)
		{	
			create_stack(checker, &checker->stacks->a, arr[i]);
			i++;
		}
	}
}

int	is_empty(t_stack *stack)
{
	if (!stack)
	{
		printf("B is empty :)\n");
		return (1);
	}
	printf("B isn't empty :(\n");
	return (0);
}

int	is_sort(t_stack *stack)
{
	t_stack *tmp;
	int i;

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

int main(int ac, char **av)
{
	t_checker	checker;

	init_checker(&checker, av);
	//print_valid_char_arr_format(expanded_params);
	if (has_duplicates(checker.arr, checker.tot_params))
		return (is_error());
	save_user_cmd(&checker);
	set_stack_a(&checker, checker.arr, checker.tot_params);
	//print_stack(checker.stacks->a);
	//print_cmd_lst(&checker);
	execute(&checker);
	//print_after_exec(&checker);
	if (is_empty(checker.stacks->b) && is_sort(checker.stacks->a))
		printf("OK\n");
	else
		is_error();
	return (0);
}
