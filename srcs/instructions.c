/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:08:46 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/12 03:05:44 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	swap_stack(int *i, int *j)
{
	int tmp;

	if ((!i || !j) || (!*i || !*j))
		return ;
	tmp = *i;
	*i = *j;
	*j = tmp;
}

t_stack	*ft_stacknew(int content)
{
	t_stack *new_list;

	new_list = malloc(sizeof(t_stack) * 1);
	if (!new_list)
		return (NULL);
	if (new_list)
	{
		new_list->i = content;
		new_list->next = NULL;
	}
	return (new_list);
}

void	ft_stackadd_front(t_stack **alst, t_stack *new)
{
	new->next = *alst;
	*alst = new;
}

void	push_stack(t_checker *checker, t_stack **from, t_stack **to)
{
	t_stack *new;
	t_stack *tmp;
	if (!from || !(*from))
		return ;
	new = ft_stacknew((*from)->i);
	ft_stackadd_front(to, new);
	tmp = (*from)->next;
	free(*from);
	(*from) = tmp;
}

void	rotate_stack(t_stack **stack)
{
	t_stack *current;
	t_stack *tmp;

	current = *stack;
	if (current == NULL)
		return ;
	tmp = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
}

int		size_stack(t_stack *stack)
{
	int i;
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack *current;
	t_stack *tmp;
	int size;
	int i;

	current = *stack;
	i = 1;
	size = size_stack(*stack);
	while (i < size - 1 && current != NULL)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
		return ;
	tmp = current;
	if (current->next != NULL)
		current = current->next;
	current->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
}
