/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:05:43 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:07:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_realloc(char *ptr, int len)
{
	char	*curr;
	int		i;

	if (!ptr)
	{
		if ((ptr = malloc(sizeof(char) * len)) == NULL)
			return (NULL);
		return (ptr);
	}
	i = -1;
	if ((curr = malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	while (ptr[++i])
		curr[i] = ptr[i];
	curr[i] = '\0';
	free(ptr);
	if ((ptr = malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	i = -1;
	while (curr[++i])
		ptr[i] = curr[i];
	free(curr);
	return (ptr);
}
