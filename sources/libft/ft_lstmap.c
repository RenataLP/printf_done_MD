/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:54:17 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/04/17 16:54:17 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*helper;

	if (lst == NULL || f == NULL)
		return (NULL);
	helper = f(lst);
	fresh = helper;
	while (lst->next)
	{
		lst = lst->next;
		if (!(helper->next = f(lst)))
		{
			free(helper->next);
			return (NULL);
		}
		helper = helper->next;
	}
	return (fresh);
}
