/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:23:48 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:24:47 by bahaas           ###   ########.fr       */
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
	int				cmd_nb;
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
void				print_cmd_lst(t_list *lst);
void				print_stack(t_stack *stack);
void				print_after_exec(t_checker *checker);

/*
**	instructions.c
*/

void				swap_stack(t_checker *checker, int *i, int *j, char *cmd);
void				push_stack(t_checker *checker, t_stack **from, t_stack **to, char *cmd);
void				rotate_stack(t_checker *checker, t_stack **stack, char *cmd);
void				reverse_rotate_stack(t_checker *checker, t_stack **stack, char *cmd);

/*
**	init.c
*/

void				init_checker(t_checker *checker, char **av);

/*
** command.c
*/

int					save_user_cmd(t_checker *checker);
void				optimize_cmd_lst(t_checker *checker);

/*
** free_checker.c
*/

void				free_checker(t_checker *checker);
void				create_cmd(t_list **list, char *line);

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
int					stack_size(t_stack *head);

/*
** select_algo.c
*/

void	select_algo(t_checker *checker);
void	sort(t_checker *checker, t_stacks *stacks, int divide_size);

/*
** get.c
*/

int		getpivot(t_stacks stacks, int index, int division, int divide_size);
int		getlen(t_stack *item);
int		getmin(t_stack *item);
int		getmax(t_stack *item);
int		getindex(t_stack *item, int nbr);

/*
** three_and_five_algo.c
*/

void	two_elements(t_checker *checker);
void	three_elements(t_checker *checker);
void	five_elements(t_checker *checker);

/*
** pswap.c
*/


/*
** init_stack.c
*/

t_stack		*new_stack(int value);
void		fill_stack_a(t_stack **stack, int value);
void		set_stack_a(t_checker *checker, int *arr, int size);

#endif
