/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:29:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/04 15:14:31 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strategy(t_benchmark *flag)
{
	if (flag->simple)
		return ("Simple");
	else if (flag->medium)
		return ("Medium");
	else if (flag->complex)
		return ("Complex");
	else
		return ("Adaptive");
}

int	print_bench(t_benchmark *flag, t_operations *op)
{
	int	sum;

	sum = op->pa + op->pb + op->sa + op->sb + op->ss + op->ra + op->rb + op->rr
		+ op->rra + op->rrb + op->rrr;
	ft_printf_err("[bench] disorder: %f%%\n", 100 * flag->disorder);
	ft_printf_err("[bench] strategy: %s\n", strategy(flag));
	ft_printf_err("[bench] total_ops: %d\n", sum);
	ft_printf_err("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", op->sa,
		op->sb, op->ss, op->pa, op->pb);
	ft_printf_err("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		op->ra, op->rb, op->rr, op->rra, op->rrb, op->rrr);
	return (0);
}
