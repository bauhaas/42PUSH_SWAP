/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:22:57 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/27 19:27:56 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	init_expanded_params(t_ps *ps, int size, char **tmp_split)
{
	int	j;

	j = -1;
	ps->expanded_params = malloc(sizeof(char *) * (size + 1));
	if (!ps->expanded_params)
		return ;
	while (++j < size)
		ps->expanded_params[j] = ft_strdup(tmp_split[j]);
	ps->expanded_params[j] = NULL;
}

static void	parse_parameters(t_ps *ps, char **av, int split_i)
{
	char	**split_params;
	int		size;
	int		i;
	int		j;

	size = 0;
	i = 0;
	while (av[++i])
	{
		split_params = ft_split(av[i], ' ');
		size = ft_strarr_len(split_params);
		if (!ps->expanded_params)
			init_expanded_params(ps, size, split_params);
		else if (ps->expanded_params)
		{
			j = ft_strarr_len(ps->expanded_params);
			ps->expanded_params = realloc(ps->expanded_params,
					sizeof(char *) * (j + size + 1));
			split_i = -1;
			while (++split_i < size)
				ps->expanded_params[j++] = ft_strdup(split_params[split_i]);
			ps->expanded_params[j] = NULL;
		}
		ft_free_strs(&split_params);
	}
}

void		init_ps(t_ps *ps, char **av)
{
	ps->stacks = malloc(sizeof(t_stacks));
	ps->stacks->a = NULL;
	ps->stacks->b = NULL;
	ps->expanded_params = NULL;
	parse_parameters(ps, av, -1);
	ps->tot_params = ft_strarr_len(ps->expanded_params);
	ps->arr = str_array_to_int_array(ps->expanded_params,
			ps->tot_params);
	print_valid_char_arr_format(ps->expanded_params);
	ps->head_cmd = NULL;
	ps->cmd = NULL;
}
