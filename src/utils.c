/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:48:40 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 15:14:32 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		n;
	int		sign;

	n = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	init_benchmark(t_stack *a, t_stack *b, t_benchmark *flag)
{
	a->data = NULL;
	b->data = NULL;
	flag->bench = 0;
	flag->simple = 0;
	flag->medium = 0;
	flag->complex = 0;
	flag->adaptive = 0;
	flag->disorder = 1.0;
}

void	init_operations(t_operations *op)
{
	op->pa = 0;
	op->pb = 0;
	op->sa = 0;
	op->sb = 0;
	op->ss = 0;
	op->ra = 0;
	op->rb = 0;
	op->rr = 0;
	op->rra = 0;
	op->rrb = 0;
	op->rrr = 0;
}

void	free_stack(t_stack *stack)
{
	if (stack->data)
		free(stack->data);
	stack->data = NULL;
	stack->size = 0;
}
