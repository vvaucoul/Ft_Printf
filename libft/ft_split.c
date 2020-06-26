/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:28:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/09 16:07:49 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isdel(char c, char del)
{
	return ((c == del) ? 1 : 0);
}

static int	countword(char const *s, char c)
{
	int nwords;
	int i;

	nwords = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && isdel(s[i], c))
			++i;
		if (s[i] && !isdel(s[i], c))
			++nwords;
		while (s[i] && !isdel(s[i], c))
			++i;
	}
	return (nwords);
}

char		**ft_split(char const *s, char c)
{
	char		**tab;
	int			y;
	static int	x;
	static int	i;
	int			j;

	if (!s || !(tab = (char **)malloc(sizeof(char *) * (countword(s, c) + 1))))
		return (NULL);
	y = -1;
	while (s[i])
	{
		++y;
		while (s[i] && isdel(s[i], c))
			++i;
		while (s[i + x] && !isdel(s[i], c))
			++x;
		if ((tab[y] = (char *)malloc(sizeof(char) * (i + x))) == NULL)
			return (NULL);
		j = 0;
		while (s[i] && !isdel(s[i], c))
			tab[y][j++] = s[i++];
		tab[y][j] = '\0';
	}
	tab[y + ((isdel(s[ft_strlen(s) - 1], c)) ? 0 : 1)] = NULL;
	return (tab);
}
