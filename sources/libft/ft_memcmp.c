/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:15:16 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/10 14:15:17 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (n--)
	{
		if (((unsigned const char *)s1)[i] != ((unsigned const char *)s2)[i])
			return ((int)((unsigned const char *)s1)[i] -
				((unsigned const char *)s2)[i]);
			i++;
	}
	return (0);
}
