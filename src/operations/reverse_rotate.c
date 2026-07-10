/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:26:15 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 15:50:01 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	temp = stack->data[i];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[i] = temp;
}

void	rra(t_context *context)
{
	if (context->a->size < 2)
		return ;
	reverse_rotate_stack(context->a);
	write(1, "rra\n", 4);
	context->op.rra++;
	context->count++;
}

void	rrb(t_context *context)
{
	if (context->b->size < 2)
		return ;
	reverse_rotate_stack(context->b);
	write(1, "rrb\n", 4);
	context->op.rrb++;
	context->count++;
}

void	rrr(t_context *context)
{
	if (context->a->size < 2 && context->b->size < 2)
		return ;
	reverse_rotate_stack(context->a);
	reverse_rotate_stack(context->b);
	write(1, "rrr\n", 4);
	context->op.rrr++;
	context->count++;
}
