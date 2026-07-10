/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:46:06 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/10 16:21:47 by yohsawa          ###   ########.fr       */
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

void	sa(t_context *context)
{
	if (context->a->size < 2)
		return ;
	swap_stack(context->a);
	write(1, "sa\n", 3);
	context->op.sa++;
	context->count++;
}

void	sb(t_context *context)
{
	if (context->b->size < 2)
		return ;
	swap_stack(context->b);
	write(1, "sb\n", 3);
	context->op.sb++;
	context->count++;
}

void	ss(t_context *context)
{
	if (context->a->size < 2 && context->b->size < 2)
		return ;
	swap_stack(context->a);
	swap_stack(context->b);
	write(1, "ss\n", 3);
	context->op.ss++;
	context->count++;
}
