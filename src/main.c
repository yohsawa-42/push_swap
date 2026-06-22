/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:53:30 by yohsawa           #+#    #+#             */
/*   Updated: 2026/06/21 17:15:48 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stack_b(t_stack *b, int size)
{
	b->size = 0;
	b->data = malloc(sizeof(int) * size);
	if (!b->data)
		return (0);
	return (1);
}

static int	exit_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	print_error();
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (0);
	a.data = NULL;
	b.data = NULL;
	if (!is_valid_input(ac, av) || !init_stack_a(&a, ac, av))
	{
		print_error();
		return (1);
	}
	if (has_duplicate(&a) || !init_stack_b(&b, a.size))
		return (exit_error(&a, &b));
	if (!is_sorted(&a) && !sort_stack(&a, &b))
		return (exit_error(&a, &b));
	free_stack(&a);
	free_stack(&b);
	return (0);
}
