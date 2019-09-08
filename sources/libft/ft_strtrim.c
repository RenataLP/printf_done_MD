/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:26:51 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/12 17:26:51 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	int		l;
	char	*str;

	i = 0;
	k = 0;
	l = 0;
	if (!s)
		return (NULL);
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	while (s[i + k] != '\0')
		k++;
	while (s[i + k] == '\t' || s[i + k] == '\n' || s[i + k] == ' ' ||
	s[i + k] == '\0')
		k--;
	if (!(str = (char *)malloc(sizeof(char) * ((ft_strlen(s) - i - k + 2)))))
		return (NULL);
	while (l <= k)
		str[l++] = s[i++];
	str[l] = '\0';
	return (str);
}
