/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:02:12 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/09 16:02:13 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	if (needle[i] == 0)
		return (&((char *)haystack)[i]);
	while (haystack[i] != '\0')
	{
		j = i;
		while (haystack[j] == needle[k])
		{
			j++;
			k++;
			if (needle[k] == '\0')
				return (&((char *)haystack)[j - k]);
		}
		i++;
		k = 0;
	}
	return (NULL);
}
