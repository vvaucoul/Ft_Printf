/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:28:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 21:02:47 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		if (!(ptr = (char *)ft_calloc(1, sizeof(char))))
			return (NULL);
	}
	else
	{
		if ((ptr = (char *)malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			ptr[i] = s[start + i];
			++i;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
