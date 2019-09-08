/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:42:02 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/15 19:42:02 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*help;
	t_list	*ptr;

	help = *alst;
	if (*alst != NULL && del != NULL)
	{
		while (help != NULL)
		{
			ptr = help->next;
			del(help->content, help->content_size);
			free(help);
			help = ptr;
		}
		*alst = NULL;
	}
}
