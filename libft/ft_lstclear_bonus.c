/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:45:08 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 17:13:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *elem;
	t_list *back_elem;

	elem = *lst;
	back_elem = *lst;
	while (elem)
	{
		back_elem = elem;
		elem = elem->next;
		ft_lstdelone(back_elem, del);
	}
	*lst = NULL;
}
