/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 17:32:06 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 18:43:31 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_data(t_stack *a, int size, char **s)
{
	int	i;

	a->size = size;
	a->data = malloc(sizeof(int) * a->size);
	if (!a->data)
		return (0);
	i = 0;
	while (i < a->size)
	{
		a->data[i] = ft_atoi(s[i]);
		i++;
	}
	return (1);
}

int	init_stack_a(t_stack *a, int ac, char **av)
{
	int		i;
	int		size;
	char	**s;

	i = 0;
	s = ft_split(av[0], ' ');
	size = 0;
	while (s[i] != NULL)
	{
		i++;
		size++;
	}
	if (size > 1)
	{
		if(!is_valid_input(size, s))
			return (0);
		return (init_data(a, size, s));
	}
	else
	{
		if(!is_valid_input(ac, av))
			return (0);
		return (init_data(a, ac, av));
	}
}

int	init_stack_b(t_stack *b, int size)
{
	b->size = 0;
	b->data = malloc(sizeof(int) * size);
	if (!b->data)
		return (0);
	return (1);
}
