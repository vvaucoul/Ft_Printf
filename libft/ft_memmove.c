/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:25:40 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 18:45:49 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*t_dst;
	char	*t_src;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	t_dst = (char *)dst;
	t_src = (char *)src;
	i = 0;
	if (t_src < t_dst)
		while (++i <= len)
			t_dst[len - i] = t_src[len - i];
	else
		while (len-- > 0)
			*(t_dst++) = *(t_src++);
	return (dst);
}
