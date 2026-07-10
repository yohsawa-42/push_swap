/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohsawa <yohsawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:15:02 by msumiji           #+#    #+#             */
/*   Updated: 2026/07/10 16:21:40 by yohsawa          ###   ########.fr       */
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

static int	count_string(char const *s)
{
	int	i;
	int	start;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
			i++;
		start = i;
		while (s[i] && s[i] != ' ' && (s[i] < 9 || s[i] > 13))
			i++;
		if (i > start)
			k++;
	}
	return (k);
}

static int	make_string(char const *s, char **a)
{
	int	i;
	int	start;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
			i++;
		start = i;
		while (s[i] && s[i] != ' ' && (s[i] < 9 || s[i] > 13))
			i++;
		if (i > start)
		{
			a[k] = ft_substr(s, start, i - start);
			if (!a[k])
				return (k);
			k++;
		}
	}
	return (0);
}

char	**ft_split(char const *s)
{
	int		n;
	int		i;
	int		j;
	char	**a;

	n = count_string(s);
	i = 0;
	a = (char **)malloc((n + 1) * sizeof(char *));
	if (a == NULL)
		return (NULL);
	j = make_string(s, a);
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
