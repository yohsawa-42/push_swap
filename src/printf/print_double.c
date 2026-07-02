/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:54:57 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/02 18:54:46 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_double(double n)
{
	int		i;
	double	x;

	i = (int)n;
	print_int(i);
	if (write(2, ".", 1) < 0)
		return (-1);
	x = n - i;
	i = (int) 100 * x;
	print_int(i);
	return (0);
}
