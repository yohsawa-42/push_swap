/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 17:32:06 by yohsawa           #+#    #+#             */
/*   Updated: 2026/06/13 17:34:46 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(t_stack *a, int ac, char **av)
{
	int	i;

	a->size = ac - 1;
	a->data = malloc(sizeof(int) * a->size);
	if (!a->data)
		return (0);
	i = 0;
	while (i < a->size)
	{
		a->data[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (1);
}
