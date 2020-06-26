/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:26:13 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 17:17:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n)
{
	size_t					i;
	unsigned char			*t_dst;
	const unsigned char		*t_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	t_dst = dst;
	t_src = src;
	i = 0;
	while (i < n)
	{
		*t_dst = *t_src;
		if (*t_dst == (unsigned char)c)
			return (dst + i + 1);
		++t_dst;
		++t_src;
		++i;
	}
	return (NULL);
}
