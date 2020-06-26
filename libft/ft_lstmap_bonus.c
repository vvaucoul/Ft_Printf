/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:15:47 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 17:15:05 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;

	if ((new_list = ft_lstnew(NULL)) == NULL)
	{
		ft_lstclear(&lst, del);
		return (lst);
	}
	if (lst)
	{
		new_list->content = f(lst->content);
		new_list->next = ft_lstmap(lst->next, f, del);
		return (new_list);
	}
	return (NULL);
}
