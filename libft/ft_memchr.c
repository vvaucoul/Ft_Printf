/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:37:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 17:17:53 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	char	*t_s;
	size_t	i;

	t_s = (char *)s;
	i = 0;
	while (i < n)
	{
		if (*t_s == c)
			return ((char *)t_s);
		++t_s;
		++i;
	}
	return (NULL);
}
