/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:28:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 19:48:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ischarset(char c, char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

static int			getstartandend(char *s1, char *set, int start_end)
{
	int i;

	i = 0;
	if (start_end)
		while (ischarset(s1[i], set) && s1[i])
			++i;
	else
	{
		i = ft_strlen(s1) - 1;
		while (ischarset(s1[i], set) && i > 0)
			--i;
	}
	return (i);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i_start;
	int		i_end;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i_start = getstartandend((char *)s1, (char *)set, 1);
	i_end = getstartandend((char *)s1, (char *)set, 0);
	if ((ptr = (char *)malloc(sizeof(char) * ((i_end > i_start) ?
	((i_end - i_start) + 2) : 2))) == NULL)
		return (NULL);
	j = 0;
	while (i_start <= i_end)
		ptr[j++] = s1[i_start++];
	ptr[j] = '\0';
	return (ptr);
}
