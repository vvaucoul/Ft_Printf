/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:21:49 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/20 15:22:07 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		n_lenght(unsigned int n)
{
	int nsize;

	nsize = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		++nsize;
	}
	return (nsize);
}

char			*ft_utoa(unsigned int n)
{
	int		i;
	int		size;
	char	*str;

	size = n_lenght(n);
	if ((str = malloc(sizeof(char) * (n_lenght(n) + 1))) == NULL)
		return (NULL);
	i = 1;
	while (size - i >= 0)
	{
		str[size - i] = n % 10 + 48;
		n /= 10;
		++i;
	}
	str[size] = '\0';
	return (str);
}
