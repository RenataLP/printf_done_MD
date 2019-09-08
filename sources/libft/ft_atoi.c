/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:22:02 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/09 19:22:03 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			k;
	int			i;
	long int	res;

	i = 0;
	k = 1;
	res = 0;
	while (ft_isspace((int)str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48) * k;
		i++;
		if (k < 0 && res > 0)
			return (0);
		if (res < 0 && k > 0)
			return (-1);
	}
	return (res);
}
