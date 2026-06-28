/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:11:10 by msumiji           #+#    #+#             */
/*   Updated: 2026/06/28 19:05:42 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define chunksize 5

static void	push_target(t_stack *a, t_stack *b, int target, int rotate)
{
	int	j;

	j = 0;
	while (j <= a->size / 2)
	{
		if (a->data[j] == target)
		{
			ra_and_pb(a, b, j);
			if (rotate)
				rb(b);
			return ;
		}
		if (a->data[a->size - j - 1] == target)
		{
			ra_and_pb(a, b, a->size - j - 1);
			if (rotate)
				rb(b);
			return ;
		}
		j++;
	}
}


static void	a_to_b(t_stack *a, t_stack *b, int *data)
{
	int	i;
	int n;
	int size;

	size = a->size;
	n = 0;
	while (n <= (size - 1) / chunksize)
	{
		i = n * chunksize;
		while (i < (n + 1) * chunksize && i < size)
		{
			push_target(a, b, data[i],
				i < n *chunksize + chunksize / 2);
			i++;
		}
		n++;
	}
}

static void b_to_a(t_stack *a, t_stack *b, int *data)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = b->size;
	while (i < size)
	{
		j = 0;
		while (j <= b->size / 2)
		{
			if (b->data[j] == data[size - i - 1])
			{
				rb_and_pa(a, b, j);
				break;
			}
			if (b->data[b->size - j - 1] == data[size - i - 1])
			{
				rb_and_pa(a, b, b->size - j - 1);
				break;
			}
			j++;
		}
		i++;
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	*data;
	int	i;
	int	size;

	i = 0;
	size = a->size;
	data = malloc(sizeof(int) * size);
	while (i < size)
	{
		data[i] = a->data[i];
		i++;
	}
	sort_array(data, size);
	a_to_b(a, b, data);
	b_to_a(a, b, data);
	free(data);
}
