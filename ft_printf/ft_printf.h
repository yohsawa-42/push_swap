/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:14:07 by yohsawa           #+#    #+#             */
/*   Updated: 2026/05/22 03:55:25 by yohsawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr(long n);
int	ft_putnbr_hex(unsigned long n, char type);
int	ft_putptr(void *ptr);

int	ft_printf(const char *str, ...);

#endif
