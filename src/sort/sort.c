/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:00:00 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/03 17:18:37 by msumiji          ###   ########.fr       */
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

<<<<<<< HEAD
static void	adaptive_sort(t_stack *a, t_stack *b, t_benchmark *flag)
=======
static int	adaptive_sort(t_stack *a, t_stack *b,
	double disorder, t_benchmark *flag)
>>>>>>> b871f14 (07031803)
{
	if (flag->disorder < 0.2)
	{
		selection_sort(a, b);
		flag->simple = 1;
		return (1);
	}
	else if (flag->disorder < 0.5)
	{
		flag->medium = 1;
		return (chunk_sort(a, b));
	}
	else
	{
		radix_sort(a, b);
		flag->complex = 1;
		return (1);
	}
}

int	sort_stack(t_stack *a, t_stack *b, t_benchmark *flag)
{
	flag->disorder = compute_disorder(a);
	if (!compress_stack(a))
		return (0);
	if (a->size <= 5)
	{
		sort_small(a, b);
		flag->small = 1;
	}
	else if (flag->simple)
		selection_sort(a, b);
	else if (flag->medium)
		return (chunk_sort(a, b));
	else if (flag->complex)
		radix_sort(a, b);
	else
<<<<<<< HEAD
	{
		flag->adaptive = 1;
		adaptive_sort(a, b, flag);
	}
=======
		return (adaptive_sort(a, b, disorder, flag));
>>>>>>> b871f14 (07031803)
	return (1);
}
