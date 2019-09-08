/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:36:05 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/11 19:36:05 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = size;
	if (i + 1 == 0)
		return (NULL);
	if (!(s = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i > 0)
	{
		s[i] = '\0';
		i--;
	}
	s[0] = '\0';
	return (s);
}
