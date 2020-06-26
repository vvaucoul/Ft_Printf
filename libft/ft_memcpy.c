/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:22:44 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 17:41:18 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t					i;
	unsigned char			*t_dst;
	const unsigned char		*t_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	t_dst = dst;
	t_src = src;
	while (i < n)
	{
		*t_dst = *t_src;
		++t_dst;
		++t_src;
		++i;
	}
	return (dst);
}
