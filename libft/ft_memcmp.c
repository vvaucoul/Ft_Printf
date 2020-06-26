/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:45:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 17:39:43 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char			*t_s1;
	const unsigned char		*t_s2;
	size_t					i;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*t_s1 != *t_s2)
			return (*t_s1 - *t_s2);
		++i;
		++t_s1;
		++t_s2;
	}
	return (0);
}
