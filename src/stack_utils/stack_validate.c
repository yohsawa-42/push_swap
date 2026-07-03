/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:00:00 by yohsawa           #+#    #+#             */
/*   Updated: 2026/07/03 18:43:13 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	check_digits(char *str, int i, int sign)
{
	long	num;

	num = 0;
	if (!is_digit(str[i]))
		return (-1);
	while (is_digit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > 2147483647) || (sign == -1 && num > 2147483648))
			return (-1);
		i++;
	}
	return (i);
}

static int	is_valid_number(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	i = check_digits(str, i, sign);
	if (i == -1)
		return (0);
	while (is_space(str[i]))
		i++;
	return (str[i] == '\0');
}

int	is_valid_input(int ac, char **av, int n)
{
	int	i;

	if (n == 0)
		return (0);
	i = n;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			return (0);
		i++;
	}
	return (1);
}
