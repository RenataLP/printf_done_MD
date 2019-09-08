/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:08:28 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/18 20:08:28 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t		len;
	size_t		i;
	char		*s2;

	i = 0;
	len = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
