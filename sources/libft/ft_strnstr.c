/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:46:59 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/09 16:47:00 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	k = 0;
	if (needle[i] == '\0')
		return (&((char *)haystack)[i]);
	while (haystack[i] != '\0' && i <= len - 1 && len > 0)
	{
		j = i;
		while (haystack[j] == needle[k] && j <= len - 1)
		{
			if (needle[k + 1] == '\0')
				return (&((char *)haystack)[j - k]);
			j++;
			k++;
		}
		i++;
		k = 0;
	}
	return (NULL);
}
