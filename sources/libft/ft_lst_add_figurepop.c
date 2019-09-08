/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_figurepop.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:34:30 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/05/17 18:34:30 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddfigurepop(f_list **alst, f_list *new)
{
	f_list *node;

	node = *alst;
	if (node == NULL)
		*alst = new;
	else
	{
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = new;
	}
}
