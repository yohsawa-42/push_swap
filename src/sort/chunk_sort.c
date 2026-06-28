/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:11:10 by msumiji           #+#    #+#             */
/*   Updated: 2026/06/28 18:15:24 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define chunksize 11

static void ra_and_pb(t_stack *a, t_stack *b, int i)
{
	int j;
	j = 0;
	if (i <= a->size / 2)
	{
		while (j < i)
		{
			ra(a);
			j++;
		}
		pb(a, b);
	}
	else
	{
		while (j < a->size - i)
		{
			rra(a);
			j++;
		}
		pb(a, b);
	}
}

static void	a_to_b(t_stack *a, t_stack *b, int *data)
{
	int	i;
	int	j;
	int n;
	int size;

	size = a->size;
	n = 0;
	while (n <= (size - 1) / chunksize)
	{
		i = n * chunksize;
		while (i < (n + 1) * chunksize && i < size)
		{
			j = 0;
			while (j <= a->size / 2)
			{
				if (a->data[j] == data[i])
				{
					ra_and_pb(a, b, j);
					if (i < n * chunksize + chunksize / 2)
						rb(b);
					break;
				}
				if (a->data[a->size - j - 1] == data[i])
				{
					ra_and_pb(a, b, a->size - j - 1);
					if (i < n * chunksize + chunksize / 2)
						rb(b);
					break;
				}
				j++;
			}
			i++;
		}
		n++;
	}
}

static void	rb_and_pa(t_stack *a, t_stack *b, int i)
{
	int	j;

	j = 0;
	if (i <= b->size / 2)
	{
		while (j < i)
		{
			rb(b);
			j++;
		}
		pa(a, b);
	}
	else
	{
		while (j < b->size - i)
		{
			rrb(b);
			j++;
		}
		pa(a, b);
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
#include <stdio.h>

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
