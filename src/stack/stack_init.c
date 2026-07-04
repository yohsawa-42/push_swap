/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 17:32:06 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 15:14:27 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(t_stack *a, int ac, char **av, int n)
{
	int	i;

	a->size = ac - n;
	a->data = malloc(sizeof(int) * a->size);
	if (!a->data)
		return (0);
	i = 0;
	while (i < a->size)
	{
		a->data[i] = ft_atoi(av[i + n]);
		i++;
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
