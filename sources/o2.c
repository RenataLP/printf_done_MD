/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:36:45 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/21 16:36:45 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int		print_splits(int space)
{
	int		i;

	i = -1;
	while (++i < space)
		ft_putchar(' ');
	return (i);
}

int		print_zero(int zero)
{
	int		i;

	i = -1;
	while (++i < zero)
		ft_putchar('0');
	return (i);
}

int		get_space(t_fl *fl, int *len)
{
	int		space;

	space = 0;
	if (fl->width && \
			(!fl->nol || fl->flagminus || fl->accuracy || fl->accuracy == 0) \
			&& fl->width > *len)
	{
		space = fl->width - *len;
		*len += space;
	}
	return (space);
}

int		get_zero(t_fl *fl, int *len, int sign)
{
	int		zeros;

	zeros = 0;
	if (fl->accuracy && fl->accuracy > *len - sign)
	{
		zeros = fl->accuracy - (*len - sign);
		*len += zeros;
	}
	if (fl->width && fl->nol && !fl->flagminus && \
			fl->accuracy == -1 && fl->width > *len)
	{
		zeros += fl->width - *len;
		*len += zeros;
	}
	return (zeros);
}

void	print_sign(intmax_t nbr, t_fl *fl)
{
	char	sign;

	sign = 0;
	if (nbr < 0)
		ft_putchar('-');
	else
	{
		if (fl->flagplus == 1)
			ft_putchar('+');
		else if (fl->flagspace == 1)
			ft_putchar(' ');
	}
}
