/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:46:06 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/05 14:19:39 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = temp;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
	a->sa++;
}

void	sb(t_stack *b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
	b->sb++;
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
	a->ss++;
}
