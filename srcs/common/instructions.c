/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:08:46 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 01:30:51 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	swap_stack(t_checker *checker, int *i, int *j, char *cmd)
{
	int tmp;

	if ((!i || !j) || (!*i || !*j))
		return ;
	tmp = *i;
	*i = *j;
	*j = tmp;
	if (cmd)
		create_cmd(&checker->cmd, cmd);
}

void	push_stack(t_checker *checker, t_stack **from, t_stack **to, char *cmd)
{
	t_stack *new;
	t_stack *tmp;

	if (!from || !(*from))
		return ;
	new = new_stack((*from)->i);
	new->next = *to;
	*to = new;
	tmp = (*from)->next;
	free(*from);
	(*from) = tmp;
	if (cmd)
		create_cmd(&checker->cmd, cmd);
}

void	rotate_stack(t_checker *checker, t_stack **stack, char *cmd)
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
	if (cmd)
		create_cmd(&checker->cmd, cmd);
}

void	reverse_rotate_stack(t_checker *checker, t_stack **stack, char *cmd)
{
	t_stack	*current;
	t_stack	*tmp;
	int		size;
	int		i;

	current = *stack;
	i = 1;
	size = stack_size(*stack);
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
	if (cmd)
		create_cmd(&checker->cmd, cmd);
}
