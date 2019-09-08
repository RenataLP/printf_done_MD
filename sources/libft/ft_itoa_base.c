/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:31:14 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/21 16:31:14 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_count(uintmax_t nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(uintmax_t value, int base)
{
	char		*ret;
	const char	*tab_base;
	int			len;
	int			i;

	if (base < 2 || base > 16)
		return (0);
	if (value == 0)
		return ("0");
	tab_base = "0123456789ABCDEF";
	len = digit_count(value, base);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	i = 1;
	while (value != 0)
	{
		ret[len - i++] = tab_base[value % base];
		value /= base;
	}
	ret[len] = '\0';
	return (ret);
}
