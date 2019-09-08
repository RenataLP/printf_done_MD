/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:49:48 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/17 15:49:48 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *help;

	help = lst;
	if (lst != NULL && f != NULL)
	{
		while (lst)
		{
			f(help);
			help = lst->next;
			lst = lst->next;
		}
	}
}
