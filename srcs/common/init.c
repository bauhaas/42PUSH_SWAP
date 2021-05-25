/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:22:57 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/25 02:42:23 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void	init_expanded_params(t_checker *checker, int size, char **tmp_split)
{
	int	j;

	j = -1;
	checker->expanded_params = malloc(sizeof(char *) * (size + 1));
	if (!checker->expanded_params)
		return ;
	while (++j < size)
		checker->expanded_params[j] = ft_strdup(tmp_split[j]);
	checker->expanded_params[j] = NULL;
}

static void	parse_parameters(t_checker *checker, char **av)
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
		if (!checker->expanded_params)
			init_expanded_params(checker, size, split_params);
		else if (checker->expanded_params)
		{
			j = ft_strarr_len(checker->expanded_params);
			checker->expanded_params = realloc(checker->expanded_params,
					sizeof(char *) * (j + 2));
			checker->expanded_params[j] = ft_strdup(av[i]);
			checker->expanded_params[j + 1] = NULL;
		}
		ft_free_strs(&split_params);
	}
}

void		init_checker(t_checker *checker, char **av)
{
	checker->stacks = malloc(sizeof(t_stacks));
	checker->stacks->a = NULL;
	checker->stacks->b = NULL;
	checker->expanded_params = NULL;
	parse_parameters(checker, av);
	checker->tot_params = ft_strarr_len(checker->expanded_params);
	checker->arr = str_array_to_int_array(checker->expanded_params,
			checker->tot_params);
	checker->head_cmd = NULL;
	checker->cmd = NULL;
}
