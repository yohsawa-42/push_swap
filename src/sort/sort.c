/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:00:00 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/04 11:36:53 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs++;
			if (a->data[i] > a->data[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / (double)total_pairs);
}

static int	adaptive_sort(t_stack *a, t_stack *b, t_benchmark *flag)
{
	if (a->size <= 5 || flag->disorder < 0.2)
	{
		flag->simple = 1;
		return (selection_sort(a, b));
	}
	else if (flag->disorder < 0.5)
	{
		flag->medium = 1;
		return (chunk_sort(a, b));
	}
	else
	{
		flag->complex = 1;
		return (radix_sort(a, b));
	}
}

int	sort_stack(t_stack *a, t_stack *b, t_benchmark *flag)
{
	flag->disorder = compute_disorder(a);
	if (!compress_stack(a))
		return (0);
	if (flag->simple)
		return (selection_sort(a, b));
	else if (flag->medium)
		return (chunk_sort(a, b));
	else if (flag->complex)
		return (radix_sort(a, b));
	else
	{
		flag->adaptive = 1;
		return (adaptive_sort(a, b, flag));
	}
}
