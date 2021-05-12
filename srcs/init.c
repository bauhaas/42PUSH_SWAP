/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:22:57 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/12 02:49:25 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static void	init_expanded_params(char ***params, int size, char **tmp_split)
{
	int	j;

	j = -1;
	*params = malloc(sizeof(char *) * (size + 1));
	if (!*params)
		return ;
	while (++j < size)
		*params[j] = ft_strdup(tmp_split[j]);
	*params[j] = NULL;
}

static char	**parse_parameters(char **av)
{
	char	**params;
	char	**split_params;
	int		size;
	int		i;
	int		j;

	size = 0;
	params = NULL;
	i = 0;
	while (av[++i])
	{
		split_params = ft_split(av[i], ' ');
		size = ft_strarr_len(split_params);
		if (!params)
			init_expanded_params(&params, size, split_params);
		else if (params)
		{
			j = ft_strarr_len(params);
			params = realloc(params, sizeof(char *) * (j + 2));
			params[j] = ft_strdup(av[i]);
			params[j + 1] = NULL;
		}
		ft_free_strs(&split_params);
	}
	return (params);
}

void		init_checker(t_checker *checker, char **av)
{
	checker->stacks = malloc(sizeof(t_stacks));
	checker->stacks->a = NULL;
	checker->stacks->b = NULL;
	checker->expanded_params = parse_parameters(av);
	checker->tot_params = ft_strarr_len(checker->expanded_params);
	checker->arr = str_array_to_int_array(checker->expanded_params, checker->tot_params);
	checker->head_cmd = NULL;
	checker->cmd = NULL;
}
