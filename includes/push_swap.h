/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:23:48 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 20:45:45 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				i;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct s_ps
{
	t_list			*cmd;
	t_list			*head_cmd;
	t_stacks		*stacks;
	int				partition_size_max;
	char			**expanded_params;
	int				*arr;
	int				tot_params;
}					t_ps;

/*
** CHECKER FOLDER
*/

void				execute(t_ps *ps);

/*
** PSWAP FOLDER
*/

void				two_elements(t_ps *ps);
void				three_elements(t_ps *ps);
void				five_elements(t_ps *ps);

void				sort(t_ps *ps, t_stacks *stacks, int divide_size);

int					select_pivot(t_stacks stacks, int index, int division);
int					select_id_to_push(int id_of_smallest, int id_of_biggest,
						int size);
int					select_min(t_stack *item);
int					select_max(t_stack *item);
int					select_id(t_stack *item, int nbr);

/*
** COMMON FOLDER
*/

void				create_cmd(t_list **list, char *line);
int					save_user_cmd(t_ps *ps);
void				optimize_cmd_lst(t_ps *ps);

void				free_ps(t_ps *ps, int is_checker);

void				init_ps(t_ps *ps, char **av);

t_stack				*new_stack(int value);
void				fill_stack_a(t_stack **stack, int value);
void				set_stack_a(t_ps *ps, int *arr, int size);

void				swap_stack(t_ps *ps, int *i, int *j, char *cmd);
void				push_stack(t_ps *ps, t_stack **from, t_stack **to,
						char *cmd);
void				rotate_stack(t_ps *ps, t_stack **stack, char *cmd);
void				reverse_rotate_stack(t_ps *ps, t_stack **stack, char *cmd);

int					*str_array_to_int_array(char **src, int size);
int					ft_strarr_len(char **arr);

void				print_valid_char_arr_format(char **arr);
void				print_av(int ac, char **av);
void				print_cmd_lst(t_list *lst);
void				print_stack(t_stack *stack);
void				print_after_exec(t_ps *ps);

int					stack_size(t_stack *head);
int					is_error(void);
int					is_empty(t_stack *stack);
int					is_sort(t_stack *stack);
int					has_duplicates(int *arr, int size);

#endif
