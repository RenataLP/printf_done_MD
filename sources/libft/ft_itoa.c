/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:58:11 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/14 18:58:11 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_zero(int i)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	str[i] = '0';
	str[i + 1] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	long int	i;
	int			len;
	char		*str;

	i = n;
	len = ft_sizeint(i);
	if (i == 0)
		return (ft_zero(0));
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (i < 0)
	{
		i = i * (-1);
		str[0] = '-';
	}
	len--;
	while (i != 0)
	{
		str[len] = (i % 10) + '0';
		i = (i / 10);
		len--;
	}
	return (str);
}
