/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:34:30 by vvaucoul          #+#    #+#             */
/*   Updated: 2019/12/23 17:46:43 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_len_address(unsigned long n, int *len)
{
	if (n > 15)
	{
		ft_get_len_address((n / 16), len);
		ft_get_len_address((n % 16), len);
	}
	else if (n < 10)
	{
		++(*len);
	}
	else
	{
		n == 10 ? ++(*len) : 0;
		n == 11 ? ++(*len) : 0;
		n == 12 ? ++(*len) : 0;
		n == 13 ? ++(*len) : 0;
		n == 14 ? ++(*len) : 0;
		n == 15 ? ++(*len) : 0;
	}
	return (*len);
}

int		ft_ptrlen(void *in)
{
	void			*output;
	unsigned long	address;
	int				len;

	len = 0;
	output = in;
	address = (unsigned long)(output);
	return (ft_get_len_address(address, &len) + 2);
}
