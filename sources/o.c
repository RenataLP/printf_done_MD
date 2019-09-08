/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:43:42 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/07/21 15:43:42 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"

int				print_zero_for_slash(uintmax_t nbr, t_fl *fl)
{
	if (fl->flaglattice && (nbr || (!nbr && fl->accuracy != -1)))
		return (1);
	return (0);
}

char			*convert_to_oct(uintmax_t nbr, int *size, int base)
{
	char		*convert;
	int			len;
	uintmax_t	temp;

	temp = nbr;
	*size = (nbr == 0) ? 2 : 1;
	len = *size;
	if (nbr == 0)
	{
		*size = 1;
		return ("0");
	}
	while ((temp /= base))
		len++;
	*size = len;
	if (!(convert = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	convert[len] = '\0';
	while (nbr)
	{
		convert[--len] = nbr % base + '0';
		nbr /= base;
	}
	return (convert);
}

int				format_unsigned(uintmax_t nbr, t_fl *fl)
{
	int		len;
	int		zero;
	int		space;
	char	*octal;
	int		sign;

	octal = convert_to_oct(nbr, &len, 8);
	sign = print_zero_for_slash(nbr, fl);
	if (!fl->accuracy && !nbr)
		len = 0;
	len += sign;
	zero = get_zero(fl, &len, 0);
	space = get_space(fl, &len);
	(!fl->flagminus) ? print_splits(space) : 0;
	print_zero_for_slash(nbr, fl) ? ft_putchar('0') : 0;
	print_zero(zero);
	if (fl->accuracy != 0 || nbr)
		ft_putstr(octal);
	if (nbr != 0)
		free(octal);
	if (fl->flagminus)
		print_splits(space);
	return (len);
}

uintmax_t		ft_octo_ditsribution(va_list list, char c, t_fl *fl, t_pf *pf)
{
	intmax_t	num;
	int			i;

	i = 0;
	if (c == 'O')
		num = (unsigned long)(va_arg(list, unsigned long int));
	else if (fl->shh == 1)
		num = (unsigned char)(va_arg(list, unsigned int));
	else if (fl->sh == 1)
		num = (unsigned short)(va_arg(list, unsigned int));
	else if (fl->sll == 1)
		num = (unsigned long long)(va_arg(list, unsigned long long int));
	else if (fl->sl == 1)
		num = (unsigned long)(va_arg(list, unsigned long int));
	else
		num = (unsigned int)(va_arg(list, unsigned int));
	num = (uintmax_t)num;
	pf->value = pf->value + format_unsigned(num, fl);
	return (0);
}

int				ft_conco(char *s, va_list list, char c, t_pf *pf)
{
	uintmax_t	x;
	t_fl		*fl1;

	fl1 = (t_fl*)malloc(sizeof(t_fl) * 1);
	fl1->sl = 0;
	fl1->sll = 0;
	fl1->sh = 0;
	fl1->shh = 0;
	ft_flags(s, fl1);
	ft_width(s, fl1);
	ft_accuracy_str(s, fl1);
	ft_lllhhh(s, fl1);
	x = ft_octo_ditsribution(list, c, fl1, pf);
	free(fl1);
	return (0);
}
