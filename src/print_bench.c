/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:29:19 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/04 17:08:31 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*selected_complexity(t_benchmark *flag)
{
	if (flag->simple)
		return ("O(n^2)");
	else if (flag->medium)
		return ("O(n√n)");
	else if (flag->complex)
		return ("O(n log n)");
	else
		return ("O(n^2)");
}

static char	*strategy(t_benchmark *flag)
{
	if (flag->adaptive)
		return ("Adaptive");
	else if (flag->simple)
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
	ft_printf_err("[bench] disorder:  %f%%\n", 100 * flag->disorder);
	ft_printf_err("[bench] strategy:  %s / %s\n", strategy(flag),
		selected_complexity(flag));
	ft_printf_err("[bench] total_ops:  %d\n", count_operations(op));
	ft_printf_err("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
		op->sa, op->sb, op->ss, op->pa, op->pb);
	ft_printf_err("[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d  rrb:  %d",
		op->ra, op->rb, op->rr, op->rra, op->rrb);
	ft_printf_err("  rrr:  %d\n", op->rrr);
	return (0);
}
