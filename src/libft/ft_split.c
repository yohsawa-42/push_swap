/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumiji <msumiji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:15:02 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/04 18:17:07 by msumiji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;
	size_t	s_len;
	size_t	min;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		min = s_len - start;
	else
		min = len;
	c = malloc(min + 1);
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < min)
	{
		c[i] = s[i + start];
		i++;
	}
	c[i] = '\0';
	return (c);
}

static int	count_string(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			n++;
			i++;
		}
		else
			i++;
	}
	return (n);
}

static int	make_string(char const *s, char c, char **a)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				a[k] = ft_substr(s, i - j, j + 1);
				if (a[k] == NULL)
					return (k);
				k++;
				j = 0;
			}
			else
				j++;
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	int		i;
	int		j;
	char	**a;

	n = count_string(s, c);
	i = 0;
	a = (char **)malloc((n + 1) * sizeof(char *));
	if (a == NULL)
		return (NULL);
	j = make_string(s, c, a);
	if (j > 0)
	{
		while (i < j)
		{
			free(a[i]);
			i++;
		}
		return (NULL);
	}
	a[n] = NULL;
	return (a);
}
