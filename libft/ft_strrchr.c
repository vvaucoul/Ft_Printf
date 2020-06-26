/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:26:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 17:35:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*end_ptr;

	i = 0;
	end_ptr = (char *)s;
	while (s[i])
	{
		++end_ptr;
		++i;
	}
	while (i >= 0)
	{
		if (s[i] == c)
			return (end_ptr);
		--end_ptr;
		--i;
	}
	return (NULL);
}
