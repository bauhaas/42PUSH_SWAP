/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:23:48 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/12 19:02:40 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				i;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct		s_checker
{
	t_list			*cmd;
	t_list			*head_cmd;
	t_stacks		*stacks;
	char			**expanded_params;
	int				*arr;
	int				tot_params;
}					t_checker;

/*
** checker_main.c
*/

int					size_stack(t_stack *stack);
int					load_stack(t_stack **a, char **av);
int					fill_stack(t_stack **a, char **av);
void				add_back(t_stack **a, t_stack *new, int num);
t_stack				*new_stack(int num);
int					check_params(char **av);
int					check_duplicate(char **av);
int					check_value(char **av);
int					is_error();

int					has_duplicates(int *arr, int size);
int					*str_array_to_int_array(char **src, int size);
int					ft_strarr_len(char **arr);
void				create_stack(t_checker *checker, t_stack **stack,
					int value);

/*
**	print.c
*/

void				print_valid_char_arr_format(char **arr);
void				print_av(int ac, char **av);
void				print_cmd_lst(t_checker *checker);
void				print_stack(t_stack *stack);
void				print_after_exec(t_checker *checker);

/*
**	instructions.c
*/

void				swap_stack(int *i, int *j);
void				push_stack(t_stack **from, t_stack **to);
void				rotate_stack(t_stack **stack);
void				reverse_rotate_stack(t_stack **stack);

/*
**	init.c
*/

void				init_checker(t_checker *checker, char **av);

/*
** command.c
*/

int					save_user_cmd(t_checker *checker);

/*
** free_checker.c
*/

void				free_checker(t_checker *checker);

/*
** execute.c
*/

void				execute(t_checker *checker);

/*
** utils.c
*/

int					is_error(void);
int					is_empty(t_stack *stack);
int					is_sort(t_stack *stack);
int					has_duplicates(int *arr, int size);

#endif
