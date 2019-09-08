/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:47:06 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/07 21:47:09 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int x;
	unsigned int l;

	i = ft_strlen(dst);
	x = i + ft_strlen(src);
	l = 0;
	if (size < i)
		return (ft_strlen(src) + size);
	if (size > i + 1)
	{
		while (src[l] && l < size - i - 1)
		{
			dst[i + l] = src[l];
			l++;
		}
		dst[i + l] = '\0';
	}
	return (x);
}
