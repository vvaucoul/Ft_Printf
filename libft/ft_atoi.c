/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:15:36 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/17 20:01:12 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skipuselesschar(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t'
	|| str[i] == '\n'
	|| str[i] == '\v'
	|| str[i] == '\r'
	|| str[i] == '\f'
	|| str[i] == ' ')
		++i;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		result;
	int		isneg;
	size_t	i;

	result = 0;
	i = skipuselesschar(str);
	isneg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		isneg = (str[i] == '-' ? 1 : 0);
		++i;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		++i;
	}
	return (isneg == 1 ? result *= -1 : result);
}
