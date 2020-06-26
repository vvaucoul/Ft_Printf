/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:26:37 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/11/08 17:34:12 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if (((unsigned char)s1[i] == 0 &&
		(unsigned char)s2[i] == 0) || i == (n - 1))
			return (0);
		++i;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
