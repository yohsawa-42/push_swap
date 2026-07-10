/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 17:32:06 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 15:50:29 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_values(int ac, char **av, int *size)
{
	char	**split;
	int		i;
	int		j;

	*size = 0;
	i = 0;
	while (i < ac)
	{
		split = ft_split(av[i]);
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!is_valid_input(1, &split[j]))
				return (free_split(split), 0);
			(*size)++;
			j++;
		}
		free_split(split);
		if (j == 0)
			return (0);
		i++;
	}
	return (*size > 0);
}

static int	fill_data(int *data, int ac, char **av)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < ac)
	{
		split = ft_split(av[i]);
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			data[k] = ft_atoi(split[j]);
			k++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}

int	init_stack_a(t_stack *a, int ac, char **av)
{
	int	size;

	if (ac == 0 || !count_values(ac, av, &size))
		return (0);
	a->data = malloc(sizeof(int) * size);
	if (!a->data)
		return (0);
	a->size = size;
	if (!fill_data(a->data, ac, av))
	{
		free_stack(a);
		return (0);
	}
	return (1);
}

int	init_stack_b(t_stack *b, int size)
{
	b->size = 0;
	b->data = malloc(sizeof(int) * size);
	if (!b->data)
		return (0);
	return (1);
}
