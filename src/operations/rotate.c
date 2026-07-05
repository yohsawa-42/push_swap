/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:15:49 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/05 14:19:59 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size < 2)
		return ;
	i = 0;
	temp = stack->data[i];
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[i] = temp;
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
	a->ra++;
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
	b->rb++;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
	a->rr++;
}
