/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:29:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/10 16:21:49 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strategy(t_benchmark *flag)
{
	if (!flag->adaptive && flag->simple)
		return ("Simple");
	else if (!flag->adaptive && flag->medium)
		return ("Medium");
	else if (!flag->adaptive && flag->complex)
		return ("Complex");
	else if (flag->simple)
		return ("Adaptive / O(n2)");
	else if (flag->medium)
		return ("Adaptive / O(n√n)");
	else
		return ("Adaptive / O(nlogn)");
}

int	print_bench(t_context *context)
{
	t_operations	*op;
	t_benchmark		*flag;

	op = &context->op;
	flag = context->flag;
	ft_printf_err("[bench] disorder: %f%%\n", 100 * flag->disorder);
	ft_printf_err("[bench] strategy: %s\n", strategy(flag));
	ft_printf_err("[bench] total_ops: %d\n", context->count);
	ft_printf_err("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", op->sa,
		op->sb, op->ss, op->pa, op->pb);
	ft_printf_err("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		op->ra, op->rb, op->rr, op->rra, op->rrb, op->rrr);
	return (0);
}
