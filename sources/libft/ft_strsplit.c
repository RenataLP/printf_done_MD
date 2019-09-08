/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:36:22 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/12 19:36:22 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numbmassive(const char *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i])
			i++;
	}
	return (n);
}

static int		ft_elemarr(const char *s, char c, int elem)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			if (n == elem)
				return (i);
			n++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i])
			i++;
	}
	return (0);
}

static int		ft_lenarr(const char *s, char c, int x)
{
	int i;

	i = 0;
	while (s[x] != c && s[x] != '\0')
	{
		x++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	char	**str;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_numbmassive(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	str[len] = NULL;
	while (i < len)
	{
		if (!(str[i] = ft_strsub(s, ft_elemarr(s, c, i),
				ft_lenarr(s, c, ft_elemarr(s, c, i)))))
		{
			while (i-- >= 0)
				free(str[i]);
			return (NULL);
		}
		i++;
	}
	return (str);
}
